JZSwipeCell
===========
Overview
-----------
Inspired by MailboxApp (http://mailboxapp.com). A UITableViewCell subclass that makes it easy to add long, short, left and right swiping of content in your table views. Features 4 swipe zones with customizable icons, colors and sizes.

Getting Started
---------------
Simple to use. Just subclass **JZSwipeCell** and add 2 lines of code to add your images and colors.

	self.imageSet = SwipeCellImageSetMake([UIImage imageNamed:@"image1"],
										  [UIImage imageNamed:@"image2"],
										  [UIImage imageNamed:@"image3"],
										  [UIImage imageNamed:@"image4"]);
	
	self.colorSet = SwipeCellColorSetMake([UIColor greenColor],
											  [UIColor redColor],
											  [UIColor brownColor],
											  [UIColor orangeColor]);

Then just implement 1 delegate method to receive messages when a swipe is detected.

	- (void)swipeCell:(JZSwipeCell*)cell triggeredSwipeWithType:(JZSwipeType)swipeType
	{
		if (swipeType != JZSwipeTypeNone)
		{
			NSIndexPath *indexPath = [self.tableView indexPathForCell:cell];
			[tableData removeObjectAtIndex:indexPath.row];
			[self.tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
			
			// add conditional statement for swipeType
		}	
	}

You can also trigger the swipe animation to run without any swipe occurring.

	JZSwipeCell *cell = (JZSwipeCell*)[self.tableView cellForRowAtIndexPath:indexPath];
	[cell triggerSwipeWithType:JZSwipeTypeShortRight];


Take a look at the examples for more info. There is one example of subclassing **JZSwipeCell** with a xib and another without.



Creator
------

[Jeremy Zedell](http://github.com/JLZ)

License
-------
JZSwipeCell is available under the MIT license. See the LICENSE file for more info.
