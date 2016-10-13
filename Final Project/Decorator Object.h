#include <cv.hpp>
#include <highgui.h>

class ComponentOpenCV
{
protected:
	cv::Mat mat;

public:
	virtual cv::Mat getMat()=0;
};

class MyMat:public ComponentOpenCV
{
public:
	MyMat()
	{
	}

	MyMat(cv::Mat mat)
	{
		//mat.copyTo(ComponentOpenCV::mat);
		ComponentOpenCV::mat = mat;
	}

	cv::Mat getMat(){return ComponentOpenCV::mat;}
	cv::Mat setMat(cv::Mat mat){ComponentOpenCV::mat = mat;}
};

class ImageProcessAlgorithms:public ComponentOpenCV
{
protected:
	cv::Mat getMat(){return ComponentOpenCV::mat;}
};


class cvtGray:public ImageProcessAlgorithms
{
private:
	ComponentOpenCV* ptrComponentOpenCV;
public:
	cvtGray(ComponentOpenCV* ptrComponentOpenCV)
	{
		this->ptrComponentOpenCV = ptrComponentOpenCV;
	}

	cv::Mat getMat()
	{
		cv::Mat tempMat;
		cv::cvtColor(ptrComponentOpenCV->getMat(),tempMat,CV_BGR2GRAY);
		//cv::imshow("cvtGray",tempMat);
		//cv::waitKey(30);
		//system("PAUSE");
		return tempMat;
	}
};


class cvtHorizFlip:public ImageProcessAlgorithms
{
private:
	ComponentOpenCV* ptrComponentOpenCV;
public:
	cvtHorizFlip(ComponentOpenCV* ptrComponentOpenCV)
	{
		this->ptrComponentOpenCV = ptrComponentOpenCV;
	}

	cv::Mat getMat()
	{
		cv::Mat tempMat;
		cv::flip(ptrComponentOpenCV->getMat(),tempMat,1);
		//cv::imshow("cvtHorizFlip",tempMat);
		//cv::waitKey(30);
		//system("PAUSE");
		return tempMat;
	}
};

class cvtEqualizeHist:public ImageProcessAlgorithms
{
private:
	ComponentOpenCV* ptrComponentOpenCV;
public:
	cvtEqualizeHist(ComponentOpenCV* ptrComponentOpenCV)
	{
		this->ptrComponentOpenCV = ptrComponentOpenCV;
	}

	cv::Mat getMat()
	{
		cv::Mat tempMat;
		cv::equalizeHist(ptrComponentOpenCV->getMat(),tempMat);
		//cv::imshow("cvtHorizFlip",tempMat);
		//cv::waitKey(30);
		//system("PAUSE");
		return tempMat;
	}
};

class cvtResizeHalfSide:public ImageProcessAlgorithms
{
private:
	ComponentOpenCV* ptrComponentOpenCV;
public:
	cvtResizeHalfSide(ComponentOpenCV* ptrComponentOpenCV)
	{
		this->ptrComponentOpenCV = ptrComponentOpenCV;
	}

	cv::Mat getMat()
	{
		cv::Mat tempMat;
		cv::Size HalfSizeOfSrc(ptrComponentOpenCV->getMat().cols/2,ptrComponentOpenCV->getMat().rows/2);
		cv::resize(ptrComponentOpenCV->getMat(),tempMat,HalfSizeOfSrc);
		//cv::imshow("cvtHorizFlip",tempMat);
		//cv::waitKey(30);
		//system("PAUSE");
		return tempMat;
	}
};