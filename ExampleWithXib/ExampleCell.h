//
//  ExampleCell.h
//  ExampleWithXib
//
//  Created by JLZ on 5/17/13.
//  Copyright (c) 2013 Jeremy Zedell. All rights reserved.
//

#import "JZSwipeCell.h"

@interface ExampleCell : JZSwipeCell

@property (nonatomic, weak) IBOutlet UILabel *label;

+ (NSString*)cellID;

@end
