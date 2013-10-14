//
//  Hello.m
//  L0301HelloiOS
//
//  Created by plter on 13-10-14.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#import "Hello.h"

@implementation Hello

-(void)sayHelloWithName:(NSString *)name withAge:(int)age{
    NSLog(@"%@ say hello,and his age is %d",name,age);
}

@end
