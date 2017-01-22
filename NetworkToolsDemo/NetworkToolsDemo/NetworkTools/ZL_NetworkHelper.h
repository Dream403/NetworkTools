//
//  CPNetworkHelper.h
//  ChargingPile
//
//  Created by ZL on 16/9/5.
//  Copyright © 2016年 LittleShrimp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#define  HttpTimeOut  30.0f

typedef NS_ENUM(NSUInteger, ZL_NetworkStatus) {
    /** 未知网络*/
    ZL_NetworkStatusUnknown,
    /** 无网络*/
    ZL_NetworkStatusNotReachable,
    /** 手机网络2G*/
     ZL_NetworkStatusReachableVia2G,
    /** 手机网络3G*/
     ZL_NetworkStatusReachableVia3G,
     /** 手机网络4G*/
     ZL_NetworkStatusReachableVia4G,
    /** WIFI网络*/
    ZL_NetworkStatusReachableViaWiFi
};
/**
 *  请求成功
 *
 *  responseObject
 */
typedef void(^ZL_NetworkRequestSuccess)(id responseObject);
/**
 *  请求失败
 *
 *  error
 */
typedef void(^ZL_NetworkRequestFailed)(NSError *error);
/**
 *  缓存数据
 *
 *  responseCache
 */
typedef void(^ZL_NetworkRequestCache)(id responseCache);
/**
 *  进度
 *
 *  progress <#progress description#>
 */
typedef void(^ZL_NetworkProgress)(NSProgress *progress);
/**
 *  网络状态
 *
 *  status
 */
typedef void(^NetworkReachabilityStatus)(ZL_NetworkStatus status);
/**
 *  响应类型
 */
typedef NS_ENUM(NSUInteger, ZL_NetworkResponseType) {

    ZL_NetworkResponseTypeJSON = 1,
    /**
     *  <#Description#>
     */
    ZL_NetworkResponseTypeXML  = 2,
    /**
     *  <#Description#>
     *
     XML / 特殊情况下，一转换服务器就无法识别的，默认会尝试转换成JSON，若失败则需要自己去转换*/
    ZL_NetworkResponseTypeData = 3
};
/**
 *  请求类型
 */
typedef NS_ENUM(NSUInteger, ZL_NetworkRequestType) {
    /**
     *
     */
    ZL_NetworkRequestTypePlainText  = 1,
    /**
     *   普通text/html
     */
    ZL_NetworkRequestTypeJSON = 2
};

@interface ZL_NetworkHelper : NSObject
/**
 *  监听网络
 */
+ (void)startListeningNetwork;
/**
 *  获取网络状态
 *
 *  status
 */
+ (void)checkNetworkStatusWithBlock:(NetworkReachabilityStatus)status;
/**
 *  
 */
+ (BOOL)currentNetworkStatus;
/**
 *  公共
 *
 *  httpHeaders <#httpHeaders description#>
 */
+(void)configPublicHttpHeaders:(NSDictionary *)httpHeaders;
/**
 *  是编码
 *
 *  shouldAutoEncode <#shouldAutoEncode description#>
 */
+(void)shouldAutoEncodeUrl:(BOOL)shouldAutoEncode;
/**
 *  请求类型  default  ZL_NetworkRequestTypePlainText

 *  requestType <#requestType description#>
 */
+(void)configRequestType:(ZL_NetworkRequestType)requestType;
/**
 *  响应类型  default  ZL_NetworkRequestTypePlainText
 *
 *  responseType ZL_NetworkResponseTypeJSON
 */
+(void)configResponseType:(ZL_NetworkResponseType)responseType;
/**
 *  取消所有请求
 */
+(void)cancleAllRequest;
/**
 *  通过URL取消请求
 *
 *  url <#url description#>
 */
+ (void)cancelRequestWithURL:(NSString *)url;
/**
 *  <#Description#>
 *
 *  URL           <#URL description#>
 *  parameters    <#parameters description#>
 *  responseCache <#responseCache description#>
 *  success       <#success description#>
 *  failure       <#failure description#>
 *
 *  @return <#return value description#>
 */
+ (NSURLSessionDataTask *)GET:(NSString *)URL
               parameters:(NSDictionary *)parameters
            responseCache:(ZL_NetworkRequestCache)responseCache
                  success:(ZL_NetworkRequestSuccess)success
                  failure:(ZL_NetworkRequestFailed)failure;
/**
 *  <#Description#>
 *
 *  URL           <#URL description#>
 *  parameters    <#parameters description#>
 *  headDic       <#headDic description#>
 *  responseCache <#responseCache description#>
 *  success       <#success description#>
 *  failure       <#failure description#>
 *
 *  @return <#return value description#>
 */
+ (NSURLSessionDataTask *)GET:(NSString *)URL
               parameters:(NSDictionary *)parameters headDic:(NSMutableDictionary *)headDic
            responseCache:(ZL_NetworkRequestCache)responseCache
                  success:(ZL_NetworkRequestSuccess)success
                  failure:(ZL_NetworkRequestFailed)failure;
/**
 *
 *
 *  URL        <#URL description#>
 *  parameters <#parameters description#>
 *  headDic    <#headDic description#>
 *  success    <#success description#>
 *  failure    <#failure description#>
 *
 *  @return <#return value description#>
 */
+ (NSURLSessionDataTask *)GET:(NSString *)URL
               parameters:(NSDictionary *)parameters headDic:(NSMutableDictionary *)headDic
                  success:(ZL_NetworkRequestSuccess)success
                  failure:(ZL_NetworkRequestFailed)failure;
/**
 *  GET 请求
 *
 *  URL        <#URL description#>
 *  parameters <#parameters description#>
 *  success    <#success description#>
 *  failure    <#failure description#>
 *
 *  @return <#return value description#>
 */
+ (NSURLSessionDataTask *)GET:(NSString *)URL
               parameters:(NSDictionary *)parameters
                  success:(ZL_NetworkRequestSuccess)success
                  failure:(ZL_NetworkRequestFailed)failure;
/**
 *  <#Description#>
 *
 *  URL           <#URL description#>
 *  parameters    <#parameters description#>
 *  responseCache <#responseCache description#>
 *  success       <#success description#>
 *  failure       <#failure description#>
 *
 *  @return <#return value description#>
 */
+ (NSURLSessionDataTask *)POST:(NSString *)URL
                parameters:(NSDictionary *)parameters
             responseCache:(ZL_NetworkRequestCache)responseCache
                   success:(ZL_NetworkRequestSuccess)success
                   failure:(ZL_NetworkRequestFailed)failure;
/**
 *  <#Description#>
 *
 *  URL           <#URL description#>
 *  parameters    <#parameters description#>
 *  headDic       <#headDic description#>
 *  responseCache <#responseCache description#>
 *  success       <#success description#>
 *  failure       <#failure description#>
 *
 *  @return <#return value description#>
 */
+ (NSURLSessionDataTask *)POST:(NSString *)URL
                parameters:(NSDictionary *)parameters headDic:(NSMutableDictionary *)headDic
             responseCache:(ZL_NetworkRequestCache)responseCache
                   success:(ZL_NetworkRequestSuccess)success
                   failure:(ZL_NetworkRequestFailed)failure;
/**
 *
 *
 *  URL        <#URL description#>
 *  parameters <#parameters description#>
 *  headDic    <#headDic description#>
 *  success    <#success description#>
 *  failure    <#failure description#>
 *
 *  @return <#return value description#>
 */
+ (NSURLSessionDataTask *)POST:(NSString *)URL
                parameters:(NSDictionary *)parameters headDic:(NSMutableDictionary *)headDic
                   success:(ZL_NetworkRequestSuccess)success
                   failure:(ZL_NetworkRequestFailed)failure;
/**
 *
 *
 *  URL        <#URL description#>
 *  parameters <#parameters description#>
 *  success    <#success description#>
 *  failure    <#failure description#>
 *
 *  @return <#return value description#>
 */
+ (NSURLSessionDataTask *)POST:(NSString *)URL
                parameters:(NSDictionary *)parameters
                   success:(ZL_NetworkRequestSuccess)success
                   failure:(ZL_NetworkRequestFailed)failure;
/**
 *  上传 图片
 *
 *  URL        <#URL description#>
 *  parameters <#parameters description#>
 *  images     <#images description#>
 *  name       <#name description#>
 *  fileName   <#fileName description#>
 *  mimeType   <#mimeType description#>
 *  progress   <#progress description#>
 *  success    <#success description#>
 *  failure    <#failure description#>
 *
 *  @return <#return value description#>
 */
+ (NSURLSessionDataTask *)uploadWithURL:(NSString *)URL
                             parameters:(NSDictionary *)parameters
                                 images:(NSArray<UIImage *> *)images
                                   name:(NSString *)name
                               fileName:(NSString *)fileName
                               mimeType:(NSString *)mimeType
                               progress:(ZL_NetworkProgress)progress
                                success:(ZL_NetworkRequestSuccess)success
                                failure:(ZL_NetworkRequestFailed)failure;
/**
 *    上传视频
 *
 *  parameters
 *  videoPath  <#videoPath description#>
 *  URL        <#URL description#>
 *  success    <#success description#>
 *  failure    <#failure description#>
 *  progress   <#progress description#>
 */
+(void)uploadVideoWithParameters:(NSDictionary *)parameters withVideoPath:(NSString *)videoPath withURL:(NSString *)URL withSuccess:(ZL_NetworkRequestSuccess)success withFailure:(ZL_NetworkRequestFailed)failure withProgress:(ZL_NetworkProgress)progress;
/**
 *  多文件上传
 *
 *  parameters <#parameters description#>
 *  videoPath  <#videoPath description#>
 *  URL        <#URL description#>
 *  success    <#success description#>
 *  failure    <#failure description#>
 *  progress   <#progress description#>
 */
+ (NSArray *)uploadMultFileWithURL:(NSString *)URL
                        parameters:(NSDictionary *)parameters
                         fileDatas:(NSArray *)dataSoucre
                              type:(NSString *)type
                              name:(NSString *)name
                          mimeType:(NSString *)mimeTypes
                          Progress:(ZL_NetworkProgress)progress
                           Success:(ZL_NetworkRequestSuccess)success
                           failure:(ZL_NetworkRequestFailed)failure;
/**
 *  下载
 *
 *  URL      <#URL description#>
 *  fileDir  <#fileDir description#>
 *  progress <#progress description#>
 *  success  <#success description#>
 *  failure  <#failure description#>
 *
 *  @return <#return value description#>
 */
+ (NSURLSessionTask *)downloadWithURL:(NSString *)URL
                              fileDir:(NSString *)fileDir
                             progress:(ZL_NetworkProgress)progress
                              success:(void(^)(NSString *))success
                              failure:(ZL_NetworkRequestFailed)failure;
@end
