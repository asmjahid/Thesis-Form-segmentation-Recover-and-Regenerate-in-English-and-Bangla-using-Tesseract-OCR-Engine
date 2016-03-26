//
//  main.cpp
//  Opencvlearn
//
//  Created by Tanvir Hasan on 7/7/15.
//  Copyright (c) 2015 Tanvir Hasan. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
bool comp(const Point &a,const Point &b)
{
    if (a.y == b.y)return a.x < b.x;
    return a.y < b.y;
}

class ImageWithCordinate
{
private:
    string Name;
    Mat Img;
    Point p;
    double Area;
public:
    ImageWithCordinate(){}
    ImageWithCordinate(Mat img,Point p_,string name="",double Area_=0.0)
    {
        img.copyTo(Img);
        p=p_;
        Name=name;
        Area=Area_;
    }
    bool operator<(const ImageWithCordinate &b)const
    {
        if(p.y!=b.p.y)return p.y<b.p.y;
        return p.x<b.p.x;
    }
    Mat getImage()const{return Img;}
    string getName()const{return Name;}
    Point getPoint()const{return p;}
    double getArea()const{return Area;}
};


class ImageMap
{

private:
    Mat A,B;
    string Field,Value;
public:
    ImageMap(){}
    ImageMap(Mat a,Mat b,string N1="",string N2="")
    {
        a.copyTo(A);
        b.copyTo(B);
        imwrite("Field.jpg",A);
        imwrite("Value.jpg",B);
        system("tesseract Field.jpg Field -l eng -psm 6 >/dev/null 2>&1");
        system("tesseract Value.jpg Value -l eng -psm 6 >/dev/null 2>&1");
        FILE *fp;
        char STR[200];
        fp=fopen("Field.txt","r");
        fgets(STR,150,fp);
        Field=STR;
        strcpy(STR,"");
        fp=fopen("Value.txt","r");
        fgets(STR,150,fp);
        Value=STR;
        system("rm -r Field.*");
        system("rm -r Value.*");
    }
    pair<Mat, Mat>getMap()const
    {
        return make_pair(A,B);
    }
    string getField(){return Field;}
    string getValue(){return Value;}
};

class ImageProcess
{

private:
    Mat Img,Gray,Blur;

    /*
     getOriginalSegment return original image segment from given conture.
     First parameter original image matrix.
     second parameter draw conture matrix.
     Third parameter is conture.
     */
    Mat getOriginalSegment(Mat Src, Mat mask, vector<Point> Conture)
    {
        Rect Roi=boundingRect(Conture); //Create a rectangle of that conture.
        Mat contureRegion;
        Mat ROI;
        Src.copyTo(ROI,mask);
        contureRegion = ROI(Roi);
        return contureRegion;
    }
    /*
     getConture return image contures.
     Take image src image as parameter.
     */
    vector<vector<Point> >getContures()
    {
        //imshow("original", Img);
        cvtColor( Img, Gray, CV_BGR2GRAY );
        //imwrite("GrayImage.jpg",Gray);
        //imshow("Gray", Gray);
        //blur(Gray,Blur, Size(3,3));
        GaussianBlur(Gray, Blur, Size(3,3), 0);
        //imwrite("GaussianBlur.jpg",Blur);
        //imshow("Blur", Blur);
        threshold(Blur, Blur,200, 255,THRESH_BINARY_INV); //Threshold the gray
        //imwrite("Threshold.jpg",Blur);
        Canny(Blur, Blur, 200, 255);
        //imwrite("Canny.jpg",Blur);
        //imshow("Canny", Blur);
        vector<vector<Point> >contours;
        vector<Vec4i>hierarchy;
        findContours(Blur, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
        return contours;
    }
    static double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0)
    {
        double dx1 = pt1.x - pt0.x;
        double dy1 = pt1.y - pt0.y;
        double dx2 = pt2.x - pt0.x;
        double dy2 = pt2.y - pt0.y;
        return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
    }

    bool isRectangle(vector<Point>contour)
    {
        vector<Point>approx;
        approxPolyDP(Mat(contour), approx, arcLength(Mat(contour), true)*0.02, true);
        if (approx.size() == 4 && fabs(contourArea(Mat(approx))) > 1000 && isContourConvex(Mat(approx)))
        {
            double maxCosine = 0;

            for( int j = 2; j < 5; j++ )
            {
                double cosine = fabs(angle(approx[j%4], approx[j-2], approx[j-1]));
                maxCosine = MAX(maxCosine, cosine);
            }

            return ( maxCosine < 0.3 );
        }
        return false;
    }
    vector<ImageWithCordinate> segmentedImage()
    {
        vector<ImageWithCordinate>ret;
        vector<vector<Point> >contours=getContures();
        set<ImageWithCordinate>SET;
        for( int i = 0; i< contours.size(); i++ )
        {
            Mat draw=Mat::zeros(Img.size(), CV_8UC3);
            drawContours(draw, contours, i, Scalar(255,255,255), CV_FILLED);
            if( isRectangle(contours[i]) )
            {
                stringstream SS;
                SS<<i;
                Mat img=getOriginalSegment(Img, draw,contours[i]);
                sort(contours[i].begin(),contours[i].end(),comp);
                if(SET.find(ImageWithCordinate(img,contours[i][0],SS.str()))==SET.end())
                {
                    SET.insert(ImageWithCordinate(img,contours[i][0],SS.str()));
                    ret.push_back(ImageWithCordinate(img,contours[i][0],SS.str(),contourArea(contours[i],false)));
                }
            }
        }
        if(ret.size()%2)
        {
            double Area=0;
            int pos=0;
            for(int i=0;i<ret.size();i++)
            {
                if(Area<ret[i].getArea())
                {
                    Area=ret[i].getArea();
                    pos=i;
                }
            }
            ret.erase(ret.begin()+pos);
        }
        return  ret;
    }
public:
    ImageProcess(){}
    ImageProcess(Mat img)
    {
        img.copyTo(Img);
    }
    vector<ImageMap> getMap()
    {
        vector<ImageMap>ret;
        vector<ImageWithCordinate>I=segmentedImage();
        sort(I.begin(), I.end());
        for (int i=0; i<I.size(); i+=2)
        {
            ret.push_back(ImageMap(I[i].getImage(),I[i+1].getImage(),I[i].getName(),I[i+1].getName()));
        }
        return ret;
    }
};
class WriteFile
{
    FILE *fp;
    string getPlainString(string s)
    {
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='\n')continue;
            temp+=s[i];
        }
        return temp;
    }
    public:
    WriteFile(string name,vector<ImageMap>I)
    {
        fp=fopen(name.c_str(),"w");
        for(int i=0;i<I.size();i++)
        {

            fprintf(fp,"%s %s\n",getPlainString(I[i].getField()).c_str(),getPlainString(I[i].getValue()).c_str());
        }
        fclose(fp);
    }
};



int main(int argc,char *argv[] )
{
    cout<<"total "<<argc<<endl;
    string Fname=argv[1];
    Fname=Fname.substr(0,Fname.find('.'))+".txt";
    cout<<Fname<<endl;
    if(argc!=2)return 0;
    Mat src,gray;
    Mat Blur;
    src = imread(argv[1], 1);
    ImageProcess A(src);
    vector<ImageMap>I=A.getMap();
    WriteFile(Fname,I);
    return 0;
}
