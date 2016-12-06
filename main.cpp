#include <iostream>
#include <ctime>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

int main()
{
    clock_t start,end;
    double duration;

    std::string imgname = "/Users/domino/img/fish_5.jpg";
    cv::Mat img = cv::imread(imgname);

    start = clock();
    cv::Mat mapx, mapy;

    std::string filename = "/Users/domino/Desktop/Four.xml";
    cv::FileStorage fs(filename, cv::FileStorage::READ);
    fs["mapx"] >> mapx;
    fs["mapy"] >> mapy;
    fs.release();
    end = clock();
    duration =(double)(end-start)/CLOCKS_PER_SEC*1000;
    printf("Time=%fms\n",duration);

    start = clock();
    cv::Mat nimg;
    cv::remap(img, nimg, mapx, mapy, CV_INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
    cv::imwrite("/Users/domino/Desktop/result.jpg", nimg);
    cv::imshow( "test",nimg);
    end = clock();
    duration =(double)(end-start)/CLOCKS_PER_SEC*1000;
    printf("Time=%fms\n",duration);
    cvWaitKey(0);
    return 0;
}



