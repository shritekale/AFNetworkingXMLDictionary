AFNetworkingXMLDictionary
=========================
Support for converting XML to NSDictionary in AFNetworking

## How To Get Started

	$ cd /path/to/MyApplication

If this is a new project, initialize git...

	$ git init

Download the AFNetworking Submodule

	$ git submodule add git@github.com:shritekale/AFNetworkingXMLDictionary.git
	$ git submodule update --init --recursive

Open your Project, go to Add Files and add class files under AFNetworking/AFNetworking and AFNetworking/AFNetworkingXMLDictionary to your project.

## Sample Usage

- Read the [AFNetworking "Getting Started" guide](https://github.com/AFNetworking/AFNetworking/wiki/Getting-Started-with-AFNetworking)

- Add missing frameworks 
   * Security.framework
   * MobileCoreServices.framework
   * SystemConfiguration.framework
   
- Import "AFXMLDictionaryRequestOperation.h" in your class

- Call the following method on a sample url

```objective-c
    NSURLRequest *req = [NSURLRequest requestWithURL:[NSURL URLWithString:SAMPLE_XML_URL]];
   
    AFXMLDictionaryRequestOperation *operation = [AFXMLDictionaryRequestOperation XMLParserRequestOperationWithRequest:req success:^(NSURLRequest *request, NSHTTPURLResponse *response, NSDictionary *xmlDictionary) {
        NSLog(@"%@",xmlDictionary);
    } failure:^(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, NSDictionary *xmlDictionary) {
        NSLog(@"%@",error);
    }];
    
    [operation start];
```

## Credits
 
- AFNetworking by [Scott Raymond](https://github.com/sco/) and [Mattt Thompson](https://github.com/mattt/) in the development of [Gowalla for iPhone](http://en.wikipedia.org/wiki/Gowalla).
 
- XMLDictionary by [Nick Lockwood](https://github.com/nicklockwood/XMLDictionary)
