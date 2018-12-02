import random
import numpy as np

class Network(object):
    def __init__(self, layers):
        '''The list ``layers`` contains the number of neurons in the
        respective layers of the network. For example, if the list
        was [2, 3, 1] then it would have 2 neurons in the first
        layer, and so on. The biases and weights for the network
        are initialized randomly, using a Gaussian distribution
        with mean 0, and variance 1.'''

        self.num_layers = len(layers)
        self.layers = layers

        # Assign weights and biases for all layers except the first (input layer)
        self.biases = [np.random.randn(y, 1) for y in layers[1:]]
        self.weights = [np.random.randn(y, x) for x, y in zip(layers[:-1], layers[1:])]

    def feedforward(self, a):
        '''Return the output of the network if ``a`` is the input'''

        # Feed the input through the layers until the output layer
        for w, b in zip(self.weights, self.biases):
            a = sigmoid(np.dot(w, a) + b)

        return a

    def SGD(self, training_data, epochs, mini_batch_size, eta, test_data=None):
        '''Train the NN using mini-batch stochastic gradient decent. The
        ``training_data`` is a list of tuples ``(x, y)`` representing the
        training input and the desired outputs respectively. The ``epochs``
        is a number that determines how many times mini-batches will be
        selected and trained with. ``mini_batch_size`` is how many random
        training inputs will be selected per mini_batch. ``eta`` is the
        learning rate. If ``test_data`` is provided then the network will
        be evaluated against the test data after each epoch and partial
        progress printed out.'''

        for i in range(epochs):
            random.shuffle(training_data)

            # create a mini_batch
            mini_batches = [training_data[k:k + mini_batch_size] for k in range(0, len(training_data), mini_batch_size)]

            for mini_batch in mini_batches:
                self.updateMiniBatch(mini_batch, eta)

            if test_data:
                print("Epoch {0}: {1} / {2}".format(i, self.evaluate(test_data), len(test_data)))
            else:
                print("Epoch {0} complete".format(i))

    def updateMiniBatch(self, mini_batch, eta):
        '''Update the network's weights and biases by applying
        gradient decent using backpropagation to a mini batch.
        The ``mini_batch`` is a list of tuples ``(x, y)`` and
        ``eta`` is the learning rate.'''

        # Gradient of weights and biases
        nabla_w = [np.zeros(w.shape) for w in self.weights]
        nabla_b = [np.zeros(b.shape) for b in self.biases]

        for x, y in mini_batch:
            # Change in gradient of weights and biases
            delta_nabla_w, delta_nabla_b = self.backprop(x, y)

            nabla_w = [nw + dnw for nw, dnw in zip(nabla_w, delta_nabla_w)]
            nabla_b = [nb + dnb for nb, dnb in zip(nabla_b, delta_nabla_b)]

        self.weights = [w - (eta / len(mini_batch)) * nw
                        for w, nw in zip(self.weights, nabla_w)]
        self.biases = [b - (eta / len(mini_batch)) * nb
                        for b, nb in zip(self.biases, nabla_b)]

    def backprop(self, x, y):
        '''Return the gradient of weights and biases as a tuple
        ``(nable_w, nabla_b)`` for the cost function. ``nabla_w``
        and ``nabla_b`` are layer-by-layer lists of numpy arrays
        similar to ``self.weights`` and ``self.biases``'''

        nabla_w = [np.zeros(w.shape) for w in self.weights]
        nabla_b = [np.zeros(b.shape) for b in self.biases]

        act = x  # Current activation
        acts = [x]  # List of all activation, layer by layer
        zs = []  # List of all z vectors (result of an activation used in the sigmoid func.)

        # Feedforward
        for w, b in zip(self.weights, self.biases):
            z = np.dot(w, act) + b
            zs.append(z)
            act = sigmoid(z)
            acts.append(act)

        # Backward pass first layer
        delta = self.costDerivative(acts[-1], y) * sigmoidDerivative(zs[-1])
        nabla_w[-1] = np.dot(delta, acts[-2].transpose())
        nabla_b[-1] = delta

        # Backpass the rest of the layers
        for l in range(2, len(self.layers)):
            z = zs[-l]
            sp = sigmoidDerivative(z)
            delta = np.dot(self.weights[-l + 1].transpose(), delta) * sp
            nabla_w[-l] = np.dot(delta, acts[-l - 1].transpose())
            nabla_b[-l] = delta

        return (nabla_w, nabla_b)

    def evaluate(self, test_data):
        '''Return the number of test inputs for which the NN
        outputs the correct result.'''
        test_results = [(np.argmax(self.feedforward(x)), y) for (x, y) in test_data]

        return sum(int(x == y) for (x, y) in test_results)

    def costDerivative(self, output_a, y):
        '''Return the vector partial derivatives
        \partial{C_x} / \partial{a} for the output activations'''
        return output_a - y

def sigmoid(z):
    '''Sigmoid function'''
    return 1.0 / (1.0 + np.exp(-z))

def sigmoidDerivative(z):
    '''Derivative of the sigmoid function.'''
    return sigmoid(z) * (1 - sigmoid(z))
