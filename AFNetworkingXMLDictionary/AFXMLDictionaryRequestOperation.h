
//
//  AFXMLDictionaryRequestOperation.h
//  AFNetworking iOS Example
//
//  Created by Shri on 19/07/13.
//  Copyright (c) 2013 Gowalla. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFHTTPRequestOperation.h"

#import <Availability.h>

/**
 `AFHTTPRequestOperation` is a subclass of `AFHTTPRequestOperation` for downloading and converting XML response data to NSDictionary.
 
 ## Acceptable Content Types
 
 By default, `AFHTTPRequestOperation` accepts the following MIME types, which includes the official standard, `application/xml`, as well as other commonly-used types:
 
 - `application/xml`
 - `text/xml`
 
 ## Use With AFHTTPClient
 
 When `AFHTTPRequestOperation` is registered with `AFHTTPClient`, the response object in the success callback of `HTTPRequestOperationWithRequest:success:failure:` will be an instance of `NSXMLParser`. On platforms that support `NSXMLDocument`, you have the option to ignore the response object, and simply use the `responseXMLDocument` property of the operation argument of the callback.
 */
@interface AFXMLDictionaryRequestOperation : AFHTTPRequestOperation

///----------------------------
/// @name Getting Response Data
///----------------------------

/**
 An `NSXMLParser` object constructed from the response data.
 */
@property (readonly, nonatomic, strong) NSXMLParser *responseXMLParser;

#ifdef __MAC_OS_X_VERSION_MIN_REQUIRED
/**
 An `NSXMLDocument` object constructed from the response data. If an error occurs while parsing, `nil` will be returned, and the `error` property will be set to the error.
 */
@property (readonly, nonatomic, strong) NSXMLDocument *responseXMLDocument;
#endif

/**
 Creates and returns an `AFHTTPRequestOperation` object and sets the specified success and failure callbacks.
 
 @param urlRequest The request object to be loaded asynchronously during execution of the operation
 @param success A block object to be executed when the operation finishes successfully. This block has no return value and takes three arguments: the request sent from the client, the response received from the server, and the XML parser constructed with the response data of request.
 @param failure A block object to be executed when the operation finishes unsuccessfully. This block has no return value and takes three arguments: the request sent from the client, the response received from the server, and the error describing the network error that occurred.
 
 @return A new XML request operation
 */
+ (instancetype)XMLParserRequestOperationWithRequest:(NSURLRequest *)urlRequest
											 success:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSDictionary *xmlDictionary))success
											 failure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, NSDictionary *xmlDictionary))failure;


#ifdef __MAC_OS_X_VERSION_MIN_REQUIRED
/**
 Creates and returns an `AFXMLRequestOperation` object and sets the specified success and failure callbacks.
 
 @param urlRequest The request object to be loaded asynchronously during execution of the operation
 @param success A block object to be executed when the operation finishes successfully. This block has no return value and takes three arguments: the request sent from the client, the response received from the server, and the XML document created from the response data of request.
 @param failure A block object to be executed when the operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data as XML. This block has no return value and takes three arguments: the request sent from the client, the response received from the server, and the error describing the network or parsing error that occurred.
 
 @return A new XML request operation
 */
+ (instancetype)XMLDocumentRequestOperationWithRequest:(NSURLRequest *)urlRequest
											   success:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSXMLDocument *document))success
											   failure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, NSXMLDocument *document))failure;
#endif

@end
