#include "face.h"

using namespace cv;
using namespace std;

#include <QDebug>

Face::Face()
{
    // Indecate the path of cascade.
    cascadeName = "D:/github/OpenCVFaceCheckIn/Major3/haarcascades/haarcascade_frontalface_alt.xml";
    matchThreshold = 200;
    judgeThreshold = 0.1;
}

Face::~Face()
{

}

bool Face::detect(cv::Mat input, cv::Mat& cut, cv::Mat draw)
{
    //    cut = input;
    //    draw = input;
    //    return true;
    Mat frameCopy, image;
    bool tryflip = false;
    CascadeClassifier cascade, nestedCascade;
    double scale = 1;
    if( !cascade.load( cascadeName ) )
    {
        std::cerr << "ERROR: Could not load classifier cascade" << std::endl;
        draw = input;
        return false;
    }

    input.copyTo( frameCopy );
    if(detectAndDraw( frameCopy, cut, cascade, nestedCascade, scale, tryflip )){
        frameCopy.copyTo(draw);
        //        cv::imshow( "result", cut );


        return true;
    }
    else
        return false;
    //       cvDestroyWindow("result");



}

bool Face::imgMatch(cv::Mat cam, cv::Mat base)
{
    if(cam.empty() || base.empty()){
        qDebug() << "Image erro.";
        return false;
    }

    // turn to grayscale
    if(cam.channels() != 1)
        cvtColor(cam, cam, CV_BGR2GRAY);
    if(base.channels() != 1)
        cvtColor(base, base, CV_BGR2GRAY);


    // Detect SIFT keypoints
    /*SiftDescriptorExtractor detector;
    vector<KeyPoint> camKey, baseKey;

    detector.detect(cam, camKey);
    detector.detect(base, baseKey);

    // Extract SIFT descriptor
    SiftDescriptorExtractor extractor;
    Mat camDes, baseDes;
    extractor.compute(cam, camKey, camDes);
    extractor.compute(base, baseKey, baseDes);

    // Brute Force Match descriptors
    BFMatcher matcher(NORM_L2, true);
    vector< vector<DMatch> > matches;
    matcher.radiusMatch(camDes, baseDes, matches, matchThreshold);

    // Counting maches = num
    int num = 0;
    for(vector< vector<DMatch> >::iterator i = matches.begin();
        i != matches.end();
        ++i)
        if(i->size() != 0)
            ++num;
    cout << "match:\t" << num << endl
         << "key of cam:\t" << camKey.size() << endl
         << "key of base:\t" << baseKey.size() << endl
         << "correct rate:\t" << (double)num / int(camKey.size() < baseKey.size() ? camKey.size() : baseKey.size())<< endl;

    Mat img_match;
    drawMatches(cam, camKey, base, baseKey, matches, img_match);//,Scalar::all(-1),Scalar::all(-1),vector<char>(),drawmode);
    imshow("matches",img_match);

    // Judge
    if((double)num / int(camKey.size() < baseKey.size() ? camKey.size() : baseKey.size()) >= judgeThreshold){
        return true;
    }
    else{
        return false;
    }

//    return true;*/

    // Initialize sift facts
    SIFT sift(0, 3, 0.03, 10, 1.6);
    vector<KeyPoint> camKeys, baseKeys;
    Mat camDescriptors, baseDescriptors;
    sift(cam, noArray(), camKeys, camDescriptors);
    sift(base, noArray(), baseKeys, baseDescriptors);

    FlannBasedMatcher FBMatcher;
    vector<Mat> trainDescriptors (1, baseDescriptors);
    FBMatcher.add(trainDescriptors);
    FBMatcher.train();
    vector< vector<DMatch> > matches;
    FBMatcher.knnMatch(camDescriptors, matches, 2);
    vector<DMatch> goodmatches;
    for(int i = 0; i<matches.size(); ++i){
        if(matches[i][0].distance < 0.6*matches[i][1].distance){
            goodmatches.push_back(matches[i][0]);
        }
    }
//    Mat img_match;
//    drawMatches(cam, camKeys, base, baseKeys, goodmatches, img_match);//,Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//    imshow("matches", img_match);


    cout << "We have: " << goodmatches.size() << " matches"<< endl;

    if(goodmatches.size() > 6)
        return true;
    else
        return false;

}

bool Face::descriptorMatch(Mat &cam, Mat &baseDescriptors)
{
    // turn to grayscale
    if(cam.channels() != 1)
        cvtColor(cam, cam, CV_BGR2GRAY);

    SIFT sift(0, 3, 0.03, 10, 1.6);
    vector<KeyPoint> camKeys;
    Mat camDescriptors;
    sift(cam, noArray(), camKeys, camDescriptors);

    FlannBasedMatcher FBMatcher;
    vector<Mat> trainDescriptors (1, baseDescriptors);
    FBMatcher.add(trainDescriptors);
    FBMatcher.train();
    vector< vector<DMatch> > matches;
    FBMatcher.knnMatch(camDescriptors, matches, 2);
    vector<DMatch> goodmatches;
    for(int i = 0; i<matches.size(); ++i){
        if(matches[i][0].distance < 0.6*matches[i][1].distance){
            goodmatches.push_back(matches[i][0]);
        }
    }

    cout << "We have: " << goodmatches.size() << " matches"<< endl;

    if(goodmatches.size() > 6)
        return true;
    else
        return false;

}

Mat Face::generateDescriptors(Mat img)
{
    if(img.channels() != 1)
        cvtColor(img, img, CV_BGR2GRAY);
    SIFT sift(0, 3, 0.03, 10, 1.6);
    vector<KeyPoint> keys;
    Mat descriptors;
    sift(img, noArray(), keys, descriptors);
    return descriptors;

}


bool Face::LoweMatch(Mat& base, Mat& cam)
{
    QString basefile = QDir::currentPath() + "/match/matchBase";
    QString camfile  = QDir::currentPath() + "/match/matchCam";

    // turn to grayscale
    if(cam.channels() != 1)
        cvtColor(cam, cam, CV_BGR2GRAY);
    if(base.channels() != 1)
        cvtColor(base, base, CV_BGR2GRAY);

    imwrite(basefile.toStdString() + ".pgm" , base);
    imwrite(camfile.toStdString() +".pgm", cam);

    qDebug() << QDir::currentPath();

//    QString file1 = QDir::currentPath() + "/data/face1";
//    QString file2 = QDir::currentPath() + "/data/face2";
    QString program = QDir::currentPath() + "/siftWin32.exe";

    string c1 = program.toStdString() + " <" + basefile.toStdString() + ".pgm" + " >" + basefile.toStdString() + ".key";
    string c2 = program.toStdString() + " <" + camfile.toStdString() + ".pgm" + " >" + camfile.toStdString() + ".key";

//    cout  << c1 << endl;
//    cout  << c2 << endl;

    int re = system(c1.c_str());
//    qDebug() << re;
    if(re!=0)
        return false;
    re = system(c2.c_str());
//    qDebug() << re;
    if(re!=0)
        return false;


    vector<string> commend;
    commend.push_back(basefile.toStdString() + ".pgm");
    commend.push_back(camfile.toStdString() + ".pgm");
    commend.push_back(basefile.toStdString() + ".key");
    commend.push_back(camfile.toStdString() + ".key");


    int x = match(commend);
    cout << "We found " << x << " match" << endl;

    if(x>10)
        return true;
    else
        return false;

}

bool Face::detectAndDraw(Mat img, Mat &faceSlice,
                         CascadeClassifier &cascade,
                         CascadeClassifier &nestedCascade,
                         double scale, bool tryflip)
{
    int i = 0;
    //double t = 0;
    vector<Rect> faces, faces2;
    const static Scalar colors[] =  { CV_RGB(0,0,255),
                                      CV_RGB(0,128,255),
                                      CV_RGB(0,255,255),
                                      CV_RGB(0,255,0),
                                      CV_RGB(255,128,0),
                                      CV_RGB(255,255,0),
                                      CV_RGB(255,0,0),
                                      CV_RGB(255,0,255)} ;
    Mat gray, smallImg( cvRound (img.rows/scale), cvRound(img.cols/scale), CV_8UC1 );

    cvtColor( img, gray, CV_BGR2GRAY );
    resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    //t = (double)cvGetTickCount();
    cascade.detectMultiScale( smallImg, faces,
                              1.1, 2, 0
                              //|CV_HAAR_FIND_BIGGEST_OBJECT
                              //|CV_HAAR_DO_ROUGH_SEARCH
                              |CV_HAAR_SCALE_IMAGE
                              ,
                              Size(100, 100) );
    if( tryflip )
    {
        flip(smallImg, smallImg, 1);
        cascade.detectMultiScale( smallImg, faces2,
                                  1.1, 2, 0
                                  //|CV_HAAR_FIND_BIGGEST_OBJECT
                                  //|CV_HAAR_DO_ROUGH_SEARCH
                                  |CV_HAAR_SCALE_IMAGE
                                  ,
                                  Size(30, 30) );
        for( vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); r++ )
        {
            faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
        }
    }
    //t = (double)cvGetTickCount() - t;
    //    printf( "detection time = %g ms\n", t/((double)cvGetTickFrequency()*1000.) );
    //cout << "detection time =" << t/((double)cvGetTickFrequency()*1000.) << "ms" << endl;
    //    bool faceFlag = false;

    // Get the pic of face.
    if(!faces.empty()){
        img(*(faces.begin())).copyTo(faceSlice);
    }
    else
        return false;
    for( vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++ )
    {
        Mat smallImgROI;
        vector<Rect> nestedObjects;
        Point center;
        Scalar color = colors[i%8];
        int radius;

        double aspect_ratio = (double)r->width/r->height;
        if( 0.75 < aspect_ratio && aspect_ratio < 1.3 )
        {
            center.x = cvRound((r->x + r->width*0.5)*scale);
            center.y = cvRound((r->y + r->height*0.5)*scale);
            radius = cvRound((r->width + r->height)*0.25*scale);
            circle( img, center, radius, color, 3, 8, 0 );
        }
        else
            rectangle( img, cvPoint(cvRound(r->x*scale), cvRound(r->y*scale)),
                       cvPoint(cvRound((r->x + r->width-1)*scale), cvRound((r->y + r->height-1)*scale)),
                       color, 3, 8, 0);
        if( nestedCascade.empty() )
            continue;
        smallImgROI = smallImg(*r);
        nestedCascade.detectMultiScale( smallImgROI, nestedObjects,
                                        1.1, 2, 0
                                        //|CV_HAAR_FIND_BIGGEST_OBJECT
                                        //|CV_HAAR_DO_ROUGH_SEARCH
                                        //|CV_HAAR_DO_CANNY_PRUNING
                                        |CV_HAAR_SCALE_IMAGE
                                        ,
                                        Size(30, 30) );
        for( vector<Rect>::const_iterator nr = nestedObjects.begin(); nr != nestedObjects.end(); nr++ )
        {
            center.x = cvRound((r->x + nr->x + nr->width*0.5)*scale);
            center.y = cvRound((r->y + nr->y + nr->height*0.5)*scale);
            radius = cvRound((nr->width + nr->height)*0.25*scale);
            circle( img, center, radius, color, 3, 8, 0 );
        }
    }
    //        cv::imshow( "result", faceSlice );
    return true;
}

