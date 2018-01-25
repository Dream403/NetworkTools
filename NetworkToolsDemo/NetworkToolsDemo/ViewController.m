//
//  ViewController.m
//  NetworkToolsDemo
//
//  Created by Snow_lu on 2017/1/22.
//  Copyright © 2017年 小虾米. All rights reserved.
//

#import "ViewController.h"
#import "ZL_NetworkHelper.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [ZL_NetworkHelper checkNetworkStatusWithBlock:^(ZL_NetworkStatus status) {
       
        NSLog(@"%ld",status);
       
    }];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
