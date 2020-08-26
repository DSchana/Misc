from __future__ import print_function
import torch

# Construct 5x3 matrix uninitialized
x = torch.empty(5, 3)
print(x)

# Construct randomly initialized matrix
x = torch.rand(5, 3)
print(x)

# Construct a matrix filled with zeros and of dtype 'long'
x = torch.zeros(5, 3, dtype=torch.long)
print(x)

# Construct tensor directly from data
x = torch.tensor([5.5, 3])
print(x)

# Constructor a tensor based on existing tensor
x = x.new_ones(5, 3, dtype=torch.double)  # new_* methods take in size
print(x)

x = torch.randn_like(x, dtype=torch.float)  # override dtype
print(x)  # Result has the same size

# CUDA Tensor
if (torch.cuda.is_available()):
    print("CUDA Found")
    device = torch.device("cuda")
    y = torch.ones_like(x, device=device)
    x = x.to(device)
    z = x + y
    print(z)
    print(z.to("cpu", torch.double))
