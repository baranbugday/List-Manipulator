import cv2

def padImage(img, nrp, ncp):
    v, h = img.shape
    vertical = int((nrp - v)/2)
    horizontal = int((ncp - h)/2)
    img_pad = cv2.copyMakeBorder(img, vertical, vertical, horizontal, horizontal, cv2.BORDER_CONSTANT, (0,0,0))
    return img_pad


