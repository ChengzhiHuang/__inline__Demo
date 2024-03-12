//
//  Warpper.h
//  RuntimeTest
//
//  Created by ChengzhiHuang on 2023/8/28.
//

#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import <execinfo.h>

NS_ASSUME_NONNULL_BEGIN

NS_INLINE void printCallerForDispatchOnce(void) {
    int depth = 4;
    void *callstack[depth];
    int frames = backtrace(callstack, depth);
    char **symbols = backtrace_symbols(callstack, frames);
    NSLog(@"%s", symbols[depth - 1]);
    free(symbols);
}

NS_INLINE BOOL HCZIsBlock(id _Nullable block) {
    static Class blockClass;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        printCallerForDispatchOnce();
//        blockClass = [^{} class];
//        while ([blockClass superclass] != NSObject.class) {
//            blockClass = [blockClass superclass];
//        }
    });
//    return [block isKindOfClass:blockClass];
    return NO;
}

static BOOL HCZStaticFunc(id _Nullable block) {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
    });
    return NO;
}

void normalPrintCallerForDispatchOnce(void);

BOOL XXXNormalExternFunction(void);

BOOL __inline__ __attribute__((always_inline)) XXXNormalInlineExternFunction(void) {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        normalPrintCallerForDispatchOnce();
    });
    return NO;
}

NS_ASSUME_NONNULL_END
