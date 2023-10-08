import numpy as np
from keras.models import Sequential
from keras.layers import MaxPooling2D

image = np.array([[2, 2, 7, 3],
				[9, 4, 6, 1],
				[8, 5, 2, 4],
				[3, 1, 2, 6]])
image = image.reshape(1, 4, 4, 1)

model = Sequential(
	[MaxPooling2D(pool_size = 2, strides = 2)])

output = model.predict(image)

output = np.squeeze(output)
print(output)
