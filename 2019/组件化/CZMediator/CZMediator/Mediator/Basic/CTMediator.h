//
//  CTMediator.h
//  CTMediator
//
//  Created by casa on 16/3/13.
//  Copyright © 2016年 casa. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString * const kCTMediatorParamsKeySwiftTargetModuleName;

@interface CTMediator : NSObject

+ (instancetype)sharedInstance;

/** 远程App调用入口，scheme://[target]/[OPEN_API]/[action]?[params] */
- (id)performActionWithUrl:(NSURL *)url completion:(void(^)(NSDictionary *info))completion;

/** 本地组件调用入口 */
- (id)performTarget:(NSString *)targetName action:(NSString *)actionName params:(NSDictionary *)params shouldCacheTarget:(BOOL)shouldCacheTarget;

/** 对缓存对象做释放 */
- (void)releaseCachedTargetWithTargetName:(NSString *)targetName;

@end
