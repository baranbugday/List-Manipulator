import cv2
import numpy as np

def greylevelslicing(img, beginingPoint, finishPoint, resultLevel):
    row, column = img.shape
    sliced_image = np.zeros((row, column), dtype = 'uint8')

    for i in range(row):
        for j in range(column):
            if img [i, j] > beginingPoint and img[i, j] < finishPoint:
                sliced_image[i,j] = resultLevel
            else:
                sliced_image[i, j] = img[i-1, j-1]

    sliced_image_visual = cv2.imshow('Sliced Image', sliced_image)
    cv2.waitKey(0)
    return sliced_image_visual