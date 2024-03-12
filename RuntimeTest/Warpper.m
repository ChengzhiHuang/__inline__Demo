//
//  Warpper.m
//  RuntimeTest
//
//  Created by ChengzhiHuang on 2023/8/28.
//

#import "Warpper.h"

void normalPrintCallerForDispatchOnce(void) {
    int depth = 4;
    void *callstack[depth];
    int frames = backtrace(callstack, depth);
    char **symbols = backtrace_symbols(callstack, frames);
    
    NSLog(@"%s", symbols[depth - 1]);
    free(symbols);
}

BOOL XXXNormalExternFunction(void) {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        normalPrintCallerForDispatchOnce();
    });
    return NO;
}
