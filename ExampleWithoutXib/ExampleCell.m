//
//  ExampleCell.m
//  ExampleWithoutXib
//
//  Created by JLZ on 5/17/13.
//  Copyright (c) 2013 Jeremy Zedell. All rights reserved.
//

#import "ExampleCell.h"

@implementation ExampleCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
	self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
		self.contentView.backgroundColor = [UIColor whiteColor];
		
		// set the 4 icons for the 4 swipe types
		self.imageSet = SwipeCellImageSetMake([UIImage imageNamed:@"pac-man"], [UIImage imageNamed:@"blinky"], [UIImage imageNamed:@"ice-cream"], [UIImage imageNamed:@"balloons"]);
    }
    return self;
}

+ (NSString*)cellID
{
	return @"ExampleCell";
}

@end
