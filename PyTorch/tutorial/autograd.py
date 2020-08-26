import torch

# Create tensor with requires_grad to track computation
x = torch.ones(2, 2, requires_grad=True)
print(x)

y = x + 2
print(y)
print(y.grad_fn)  # y was created as a result of an operation so it has a grad_fn (gradient) function

z = y * y * 3
out = z.mean()
print(z, out)

a = torch.randn(2, 2)
a = ((a * 3) / (a - 1))
print(a.requires_grad)
a.requires_grad_(True)
print(a.requires_grad)
b = (a * a).sum()
print(b.grad_fn)

# Backprop time. Out contains a single Scalar.
# out.backward() is equivalent to out.backward(torch.tensor(1.))
out.backward()
print(x.grad)  # print gradients d(out) / dx
