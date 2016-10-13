#include <cv.hpp>
#include <highgui.h>
#include <windows.h>
#include "Decorator Object.h"
using namespace std;

int main ()
{
	bool isDecorator = true;
	string strImagePath = "繼往開來.JPG";
	while(1)
	{
		cout << "請選擇 1.Decorator流程  0.循序流程 ：" ;
		cin >> isDecorator;
		
		if(isDecorator)
		{
			cout << "選擇了 Decorator流程" << endl;
			MyMat frameRaw(cv::imread(strImagePath));
			cv::imshow("frameRaw",frameRaw.getMat());
			cv::waitKey(30);
			system("PAUSE");//停下來看原圖

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
			QueryPerformanceCounter((LARGE_INTEGER*)&BeforeTimeMark);//取前的時間點

				ptrComponentOpenCV->getMat();//要被測量時間的程式碼

			QueryPerformanceFrequency((LARGE_INTEGER*)&NowFreq);//取得目前 CPU frequency
			QueryPerformanceCounter((LARGE_INTEGER*)&AfterTimeMark);//取後的時間點
			long decodeDulation=(((AfterTimeMark - BeforeTimeMark) * 1000)/NowFreq);
			printf("執行費時:%dms",decodeDulation);

			cv::imshow("處理後",ptrComponentOpenCV->getMat());
		}
		else
		{
			cout << "選擇了 循序流程" << endl;
			cv::Mat frameRaw =cv::imread(strImagePath);
			cv::Mat frameAfterProcess;
			cv::imshow("frameRaw",frameRaw);
			cv::waitKey(30);
			system("PAUSE");//停下來看原圖

			__int64 BeforeTimeMark=0;
			__int64 AfterTimeMark=0;
			__int64 NowFreq=0;
			QueryPerformanceCounter((LARGE_INTEGER*)&BeforeTimeMark);//取前的時間點

				cv::resize(frameRaw,frameAfterProcess,cv::Size(frameRaw.cols/4,frameRaw.rows/4));
				cv::flip(frameAfterProcess,frameAfterProcess,1);
				cv::cvtColor(frameAfterProcess,frameAfterProcess,CV_BGR2GRAY);
				cv::equalizeHist(frameAfterProcess,frameAfterProcess);

			QueryPerformanceFrequency((LARGE_INTEGER*)&NowFreq);//取得目前 CPU frequency
			QueryPerformanceCounter((LARGE_INTEGER*)&AfterTimeMark);//取後的時間點
			long decodeDulation=(((AfterTimeMark - BeforeTimeMark) * 1000)/NowFreq);
			printf("執行費時:%dms",decodeDulation);

			cv::imshow("處理後",frameAfterProcess);
		}

		cout << "\n\n" <<endl;
		cv::waitKey(30);
		system("PAUSE");	
		cv::destroyAllWindows();
	}
}
