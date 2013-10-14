//
//  ViewController.m
//  L0301HelloiOS
//
//  Created by plter on 13-10-14.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    Hello *h = [[[Hello alloc] init] autorelease];
    [h sayHelloWithName:@"ChenYu" withAge:10];
    
//    [h retain];
//    [h release];
//    [h dealloc];
//    NSLog(@"Retain count %d",[h retainCount]);

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
