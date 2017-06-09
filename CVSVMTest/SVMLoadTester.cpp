//
//  SVMLoadTester.cpp
//  CVSVMTest
//
//  Created by Christopher Palmer on 6/8/17.
//  Copyright © 2017 Christopher Palmer. All rights reserved.
//
#include <opencv2/opencv.hpp>
#include "SVMLoadTester.hpp"
using namespace cv;
using namespace ml;
template <typename TClasses>
bool readSVMFileXML(const std::string& path) {
    
    std::string fullPath = path + "/svm.xml";
    Ptr<SVM> svm = SVM::load(fullPath);
    
    // get the informationfrom the Support Vector Library
    int decisionFuncIndex = 0;
    Mat supportVectors = svm->getSupportVectors();
    Mat alpha(supportVectors.rows,1, CV_32FC1);
    Mat svidx(supportVectors.rows,1,CV_32FC1);
    double rho = svm->getDecisionFunction(decisionFuncIndex, alpha, svidx);
    double svidxTmp, alphaTmp;
    
    auto tc = svm->getTermCriteria();
    auto a = svm->getDefaultName();
    std::string infoPath = path + "/svminfo.txt";

    std::string svmInfoPath(path + "/svm_info.txt");
    std::ofstream svmInfoStream;
    svmInfoStream.open(svmInfoPath.c_str());
    std::cout << "opening file resultted in " << svmInfoStream.is_open() << std::endl;
    std::cout << "Loaded SVM Classifier " << fullPath << " " << svm->isTrained() << std::endl;
    svmInfoStream << "Rho: " << rho << " " << a << "\r\n";
    for(int svIndex=0; svIndex < supportVectors.rows; svIndex++) {
        svidxTmp = svidx.at<double>(svIndex,1);
        alphaTmp = alpha.at<double>(svIndex,1);
        svmInfoStream << "Svidx: " << svidxTmp << " Alpha: " << alphaTmp;
        svmInfoStream << " Vector: " << supportVectors.row(svIndex) << "\r\n";
    }

    svmInfoStream.close();
    return true;
}
