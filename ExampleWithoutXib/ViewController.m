//
//  ViewController.m
//  ExampleWithoutXib
//
//  Created by JLZ on 5/17/13.
//  Copyright (c) 2013 Jeremy Zedell. All rights reserved.
//

#import "ViewController.h"

#define kCellTextKey @"kCellTextKey"
#define kCellTagKey @"kCellTagKey"

static NSMutableArray *tableData;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	
	tableData = [[NSMutableArray alloc] initWithCapacity:20];
	for (int i = 0; i < 20; ++i)
	{
		[tableData addObject:[NSString stringWithFormat:@"Cell %d", i]];
	}
}

#pragma mark - UITableViewDelegate + UITableViewDataSource methods

- (UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
	ExampleCell *cell = [self.tableView dequeueReusableCellWithIdentifier:[ExampleCell cellID]];
	if (!cell)
	{
		cell = [[ExampleCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:[ExampleCell cellID]];
	}
	
	cell.textLabel.text = tableData[indexPath.row];
	cell.delegate = self;
	
	return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
	JZSwipeCell *cell = (JZSwipeCell*)[self.tableView cellForRowAtIndexPath:indexPath];
	[cell triggerSwipeWithType:(JZSwipeType)((arc4random() % 4) + 1)];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
	return tableData.count;
}

- (UIView*)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
	return nil;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
	return 0;
}

#pragma mark - JZSwipeCellDelegate methods

- (void)swipeCell:(JZSwipeCell*)cell triggeredSwipeWithType:(JZSwipeType)swipeType
{
	if (swipeType != JZSwipeTypeNone)
	{
		NSIndexPath *indexPath = [self.tableView indexPathForCell:cell];
		if (indexPath)
		{
			[tableData removeObjectAtIndex:indexPath.row];
			[self.tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
		}
	}
	
}

- (void)swipeCell:(JZSwipeCell *)cell swipeTypeChangedFrom:(JZSwipeType)from to:(JZSwipeType)to
{
	// perform custom state changes here
	NSLog(@"Swipe Changed From (%d) To (%d)", from, to);
}

@end
