import cv2

from padImage import *
from cropImage import *

img1 = cv2.imread(r"C:\Users\PC\Desktop\IMG", 0)

def filterImage(img, filter):
    h, w = img.shape
    padded_img = padImage(img, h+2, w+2)
    crop_array = [1,1,h+1,w+1]
    
    xdhpf = np.array([[-1, 0, 1],
                    [-1, 0, 1],
                    [-1, 0, 1]])

    ydhpf = np.array([[-1, -1, -1],
                    [ 0, 0, 0],
                    [ 1, 1, 1]])

    lf = np.array([[0, 1, 0],
                [1, -4, 1],
                [0, 1, 0]], dtype = np.float32)

    gaussian = np.array([[0.0233, 0.106, 0.0233],
                        [0.106, 0.421, 0.106],
                        [0.0233, 0.106, 0.0233]])

    uaf = np.ones((3,3), np.float32)/9

    if (filter == 'xdhpf'):
        filtered_img = cv2.filter2D(padded_img, -1, xdhpf)
        cropped_result = cropImage(filtered_img, crop_array)
        return cropped_result
    elif (filter == 'ydhpf'):
        filtered_img = cv2.filter2D(padded_img, -1, ydhpf)
        cropped_result = cropImage(filtered_img, crop_array)
        return cropped_result
    elif (filter == 'lf'):
        filtered_img = cv2.filter2D(padded_img, -1, lf)
        cropped_result = cropImage(filtered_img, crop_array)
        return cropped_result
    elif (filter == 'uaf'):
        filtered_img = cv2.filter2D(padded_img, -1, uaf)
        cropped_result = cropImage(filtered_img, crop_array)
        return cropped_result
    elif (filter == 'gaf'):
        filtered_img = cv2.filter2D(padded_img, -1, gaussian)
        cropped_result = cropImage(filtered_img, crop_array)
        return cropped_result
