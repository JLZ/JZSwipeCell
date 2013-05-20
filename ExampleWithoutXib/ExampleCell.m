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
		self.swipeView.backgroundColor = [UIColor whiteColor];
		
		// remove the labels from their superview and attach them to swipeView
		[@[self.textLabel, self.detailTextLabel] makeObjectsPerformSelector:@selector(removeFromSuperview)];
		[self.swipeView addSubview:self.textLabel];
		[self.swipeView addSubview:self.detailTextLabel];
		
		// set the 4 icons for the 4 swipe types
		self.imageSet = SwipeCellImageSetMake([UIImage imageNamed:@"pac-man"], [UIImage imageNamed:@"blinky"], [UIImage imageNamed:@"ice-cream"], [UIImage imageNamed:@"balloons"]);
    }
    return self;
}

- (void)layoutSubviews
{
	[super layoutSubviews];
	
	// make sure to set the swipeView's frame to fill the cell
	self.swipeView.frame = self.backgroundView.frame;
}

- (void)prepareForReuse
{
	[super prepareForReuse];
	self.textLabel.text = nil;
}

+ (NSString*)cellID
{
	return @"ExampleCell";
}

@end
