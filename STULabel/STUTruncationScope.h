// Copyright 2017–2018 Stephan Tolksdorf

#import "STUDefines.h"

#import <Foundation/Foundation.h>
#import <STULabel/STUMultiplePlatformDefines.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#endif

#if TARGET_OS_OSX
#import <AppKit/AppKit.h>
#endif

#import <CoreText/CoreText.h>

STU_ASSUME_NONNULL_AND_STRONG_BEGIN

NS_SWIFT_NAME(stuTruncationScope)
extern const NSAttributedStringKey STUTruncationScopeAttributeName;

/// A paragraph-level attribute that establishes a separate truncation scope for the attributed
/// paragraph(s).
///
/// Equality for @c STUTruncationScope instances is defined as pointer equality.
STU_EXPORT
@interface STUTruncationScope : NSObject <NSSecureCoding>

- (instancetype)initWithMaximumNumberOfLines:(int32_t)maximumNumberOfLines;

- (instancetype)initWithMaximumNumberOfLines:(int32_t)maximumNumberOfLines
                      lastLineTruncationMode:(CTLineTruncationType)lastLineTruncationMode
                             truncationToken:(NSAttributedString * __nullable)truncationToken;

- (instancetype)initWithMaximumNumberOfLines:(int32_t)maximumNumberOfLines
                      lastLineTruncationMode:(CTLineTruncationType)lastLineTruncationMode
                             truncationToken:(NSAttributedString * __nullable)truncationToken
                      truncatableStringRange:(NSRange)stringRange
  NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)decoder
  NS_DESIGNATED_INITIALIZER;

@property (readonly) int32_t maximumNumberOfLines;

@property (readonly) CTLineTruncationType lastLineTruncationMode;

@property (readonly, nullable) NSAttributedString *truncationToken;

@property (readonly) NSRange truncatableStringRange;

@end

STU_ASSUME_NONNULL_AND_STRONG_END
