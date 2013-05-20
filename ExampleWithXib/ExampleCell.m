//
//  ExampleCell.m
//  ExampleWithXib
//
//  Created by JLZ on 5/17/13.
//  Copyright (c) 2013 Jeremy Zedell. All rights reserved.
//

#import "ExampleCell.h"

@implementation ExampleCell

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
		
    }
    return self;
}

- (void)awakeFromNib
{
	[super awakeFromNib];
	self.imageSet = SwipeCellImageSetMake([UIImage imageNamed:@"pac-man"], [UIImage imageNamed:@"blinky"], [UIImage imageNamed:@"ice-cream"], [UIImage imageNamed:@"balloons"]);
}

- (void)prepareForReuse
{
	[super prepareForReuse];
	self.label.text = nil;
}

+ (NSString*)cellID
{
	return @"ExampleCell";
}

@end
