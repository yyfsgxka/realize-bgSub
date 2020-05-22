#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture capVideo;//实例化一个videocapture类，名称为cap
	capVideo.open(0);//
	if (!capVideo.isOpened())
	{
		std::cout << "不可打开视频文件" << std::endl;
		return -1;
	}
	double fps = capVideo.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	
	int cnt = 0;
	Mat frame, bgMat, subMat, bny_subMat;
	while (1)
	{
		capVideo >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);

		if (cnt == 0) {
			frame.copyTo(bgMat);

		}
		else {
			//第二帧开始背景差分
			//背景图像和当前图像相减
			absdiff(frame, bgMat, subMat);
			//差分结果二值化
			threshold(subMat, bny_subMat, 50, 255, CV_THRESH_BINARY);
			imshow("b_subMat", bny_subMat);
			imshow("subMat", subMat);

			waitKey(30);
			
		}
		cnt++;

	}


return 0;
}

