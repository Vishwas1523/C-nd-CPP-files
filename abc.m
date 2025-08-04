#import <Foundation/Foundation.h>
@interface Greeter : NSObject
- (void)greet;
@end
@implementation Greeter
- (void)greet {
    NSLog(@"Hello from Objective-C!");
}
@end
int main() {
    @autoreleasepool {
        Greeter *g = [[Greeter alloc] init];
        [g greet];
    }
    return 0;
}