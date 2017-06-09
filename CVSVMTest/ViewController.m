//
//  ViewController.m
//  CVSVMTest
//
//  Created by Christopher Palmer on 6/8/17.
//  Copyright © 2017 Christopher Palmer. All rights reserved.
//

#import "ViewController.h"
#import "SVMLoadTester.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSString *tempPath = NSTemporaryDirectory();
    readSVMFileXML([tempPath UTF8String]);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
