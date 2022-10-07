#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv){

    if (argc != 2){
        cout << " Usage: " << argv[0] << " ImageToLoadAndDisplay" << endl;
        return -1;
    }
    int x, y, w, h;  
    cin >> x >> y >> w >> h;        // 輸入位置

    Mat image;
    Mat reimage(Size(x - w, y - h), CV_8UC3);         // 新增一個目標大小的圖
    image = imread(argv[1], IMREAD_COLOR);           // Read the file
    namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
    imshow("Display window", image);                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    
    /*
        利用迴圈將對應的原始圖座標像素值給到新圖片
    */
    for (int i = 0; i < x - w; i++) {
        for (int j = 0; j < y - h; j++) {
            reimage.at<Vec3b>(j, i)[0] = image.at<Vec3b>(j + h, i + x)[0];    
            reimage.at<Vec3b>(j, i)[1] = image.at<Vec3b>(j + h, i + x)[1];
            reimage.at<Vec3b>(j, i)[2] = image.at<Vec3b>(j + h, i + x)[2];
        }
    }
    
    imshow("Display window1", reimage); //SHOW PICTURE
    waitKey(0);
    return 0;
}

