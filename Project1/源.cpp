#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture capVideo;//ʵ����һ��videocapture�࣬����Ϊcap
	capVideo.open(0);//
	if (!capVideo.isOpened())
	{
		std::cout << "���ɴ���Ƶ�ļ�" << std::endl;
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
			//�ڶ�֡��ʼ�������
			//����ͼ��͵�ǰͼ�����
			absdiff(frame, bgMat, subMat);
			//��ֽ����ֵ��
			threshold(subMat, bny_subMat, 50, 255, CV_THRESH_BINARY);
			imshow("b_subMat", bny_subMat);
			imshow("subMat", subMat);

			waitKey(30);
			
		}
		cnt++;

	}


return 0;
}

