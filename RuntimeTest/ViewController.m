//
//  ViewController.m
//  RuntimeTest
//
//  Created by ChengzhiHuang on 2023/7/19.
//

#import "ViewController.h"
#import "Warpper.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self testVoid];
    [self testFloat];
}

#pragma mark - TestMethod
- (void)testVoid {
    HCZIsBlock(nil);
    HCZStaticFunc(nil);
    XXXNormalInlineExternFunction();
}

- (CGFloat)testFloat {
    HCZIsBlock(nil);
    HCZStaticFunc(nil);
    XXXNormalInlineExternFunction();
    return 3.f;
}

@end
