import torch
import torch.nn as nn
import torch.nn.functional as F

# NOTE: Back propagation is automatically defined using autograd

class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()

        # 1 input image channel, 6 output channels, 3x3 square convolution kernel
        self.conv1 = nn.Conv2d(1, 6, 3)
        self.conv2 = nn.Conv2d(6, 16, 3)

        # An affine operation: y = Wx + b
        self.fc1 = nn.Linear(16 * 6 * 6, 120)  # 6 * 6 from image dimension
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)

    def forward(self, x):
        # Max pooling over a (2, 2) window
        # If the size is a square you can only specify a single number
        x = F.max_pool2d(F.relu(self.conv1(x)), (2, 2))
        x = F.max_pool2d(F.relu(self.conv2(x)), 2)

        x = x.view(-1, self.num_flat_features(x))
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.fc3(x)

        return x

    def num_flat_features(self, x):
        size = x.size()[1:]  # all dimensions except the batch dimension
        num_features = 1

        for s in size:
            num_features *= s

        return num_features

net = Net()
print(net)

# Learnable parameters are returned by net.parameters()
params = list(net.parameters())
print(len(params))
for p in params:
    print(p.size())

# Try random 32 x 32 input
inp = torch.randn(1, 1, 32, 32)
out = net(inp)
print(out)

# Zero the gradient buffers of all parameters and backprop with random gradients
net.zero_grad()
out.backward(torch.randn(1, 10))

### Loss calculation

output = net(inp)
target = torch.randn(10)  # a dunny target, for example
target = target.view(1, -1)
criterion = nn.MSELoss()

loss = criterion(output, target)
print(loss)

# If we follow 'loss' in the backwards direction, using its .grad_fn attribute, we see a graph of computations like
# input -> conv2d -> relu -> maxpool2d -> conv2d -> relu -> maxpool2d
#       -> view -> linear -> relu -> linear -> relu -> linear
#       -> MSELoss
#       -> loss
#
# When we call loss.backward(), the whole graph is differentiated w.r.t the loss, and all Tensors in the graph with requires_grad=True will have their .grad Tensor accumulated with the gradient
#
# EXAMPLE: This goes a few steps back
print(loss.grad_fn)  # MSELoss
print(loss.grad_fn.next_functions[0][0])  # Linear
print(loss.grad_fn.next_functions[0][0].next_functions[0][0])  # ReLU

### Backprop

net.zero_grad()  # zeros the gradient buffers of all parameters

print("conv1.bias.grad before backward")
print(net.conv1.bias.grad)

loss.backward()

print("conv1.bias.grad after backward")
print(net.conv1.bias.grad)

### Update the weights

# Simplest method, stochastic gradient decent:
# weight = weight - learning_rate * gradient

learning_rate = 0.01
for f in net.parameters():
    f.data.sub_(f.grad.data * learning_rate)

# For more optimized update rules use torch.optim
import torch.optim as optim

# Create optimizer
optimizer = optim.SGD(net.parameters(), lr=0.01)

# In training loop
optimizer.zero_grad()  # Zero the gradient buffers
output = net(inp)
loss = criterion(output, target)
loss.backward()
optimizer.step()  # Does the update
