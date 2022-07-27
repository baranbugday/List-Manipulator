import cv2
import numpy as np

#array should be in (x1, y1, x2, y2) format
def cropImage(img, cropArray): 
    x1,y1,x2,y2 = cropArray
    cropped_image = img[x1:x2,y1:y2]
    return cropped_image

