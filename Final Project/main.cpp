#include <cv.hpp>
#include <highgui.h>
#include <windows.h>
#include "Decorator Object.h"
using namespace std;

int main ()
{
	bool isDecorator = true;
	string strImagePath = "�~���}��.JPG";
	while(1)
	{
		cout << "�п�� 1.Decorator�y�{  0.�`�Ǭy�{ �G" ;
		cin >> isDecorator;
		
		if(isDecorator)
		{
			cout << "��ܤF Decorator�y�{" << endl;
			MyMat frameRaw(cv::imread(strImagePath));
			cv::imshow("frameRaw",frameRaw.getMat());
			cv::waitKey(30);
			system("PAUSE");//���U�Ӭݭ��

			ComponentOpenCV* ptrComponentOpenCV = NULL;
			string KeyinOrder = "";

			ptrComponentOpenCV = &frameRaw;
			ptrComponentOpenCV = new cvtResizeHalfSide(ptrComponentOpenCV);
			ptrComponentOpenCV = new cvtResizeHalfSide(ptrComponentOpenCV);
			ptrComponentOpenCV = new cvtHorizFlip(ptrComponentOpenCV);
			ptrComponentOpenCV = new cvtGray(ptrComponentOpenCV);
			ptrComponentOpenCV = new cvtEqualizeHist(ptrComponentOpenCV);

			__int64 BeforeTimeMark=0;
			__int64 AfterTimeMark=0;
			__int64 NowFreq=0;
			QueryPerformanceCounter((LARGE_INTEGER*)&BeforeTimeMark);//���e���ɶ��I

				ptrComponentOpenCV->getMat();//�n�Q���q�ɶ����{���X

			QueryPerformanceFrequency((LARGE_INTEGER*)&NowFreq);//���o�ثe CPU frequency
			QueryPerformanceCounter((LARGE_INTEGER*)&AfterTimeMark);//���᪺�ɶ��I
			long decodeDulation=(((AfterTimeMark - BeforeTimeMark) * 1000)/NowFreq);
			printf("����O��:%dms",decodeDulation);

			cv::imshow("�B�z��",ptrComponentOpenCV->getMat());
		}
		else
		{
			cout << "��ܤF �`�Ǭy�{" << endl;
			cv::Mat frameRaw =cv::imread(strImagePath);
			cv::Mat frameAfterProcess;
			cv::imshow("frameRaw",frameRaw);
			cv::waitKey(30);
			system("PAUSE");//���U�Ӭݭ��

			__int64 BeforeTimeMark=0;
			__int64 AfterTimeMark=0;
			__int64 NowFreq=0;
			QueryPerformanceCounter((LARGE_INTEGER*)&BeforeTimeMark);//���e���ɶ��I

				cv::resize(frameRaw,frameAfterProcess,cv::Size(frameRaw.cols/4,frameRaw.rows/4));
				cv::flip(frameAfterProcess,frameAfterProcess,1);
				cv::cvtColor(frameAfterProcess,frameAfterProcess,CV_BGR2GRAY);
				cv::equalizeHist(frameAfterProcess,frameAfterProcess);

			QueryPerformanceFrequency((LARGE_INTEGER*)&NowFreq);//���o�ثe CPU frequency
			QueryPerformanceCounter((LARGE_INTEGER*)&AfterTimeMark);//���᪺�ɶ��I
			long decodeDulation=(((AfterTimeMark - BeforeTimeMark) * 1000)/NowFreq);
			printf("����O��:%dms",decodeDulation);

			cv::imshow("�B�z��",frameAfterProcess);
		}

		cout << "\n\n" <<endl;
		cv::waitKey(30);
		system("PAUSE");	
		cv::destroyAllWindows();
	}
}