import torch

x = torch.randn(3, requires_grad=True)

y = x * 2
while y.data.norm() < 1000:
    y *= 2

print(y)

# NOTE: y is not a scalar; torch.autograd could not computer the full jacobian directly. If we we just want the vector-jacobian product, simply pass the vector to .backward as an argument

v = torch.tensor([0.1, 1.0, 0.0001], dtype=torch.float)
y.backward(v)

print(x.grad)
