//
// JZSwipeCell.h
//
// Copyright (C) 2013 Jeremy Zedell
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is furnished
// to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import <UIKit/UIKit.h>

/* -------------- SwipeCellImageSet -------------- */
@interface SwipeCellImageSet : NSObject
@property (nonatomic, strong) UIImage *shortRightSwipeImage;
@property (nonatomic, strong) UIImage *longRightSwipeImage;
@property (nonatomic, strong) UIImage *shortLeftSwipeImage;
@property (nonatomic, strong) UIImage *longLeftSwipeImage;
@end

/**
 Use this method to set `JZSwipeCell`'s `imageSet` property.
 @param shortRightSwipeImage The icon to display during a short swipe to the right
 @param longRightSwipeImage The icon to display during a long swipe to the right
 @param shortLeftSwipeImage The icon to display during a short swipe to the left
 @param longLeftSwipeImage The icon to display during a long swipe to the left
 */
NS_INLINE SwipeCellImageSet* SwipeCellImageSetMake(UIImage *shortRightSwipeImage, UIImage *longRightSwipeImage, UIImage *shortLeftSwipeImage, UIImage *longLeftSwipeImage)
{
	SwipeCellImageSet *is = [[SwipeCellImageSet alloc] init];
	is.shortRightSwipeImage = shortRightSwipeImage;
	is.longRightSwipeImage = longRightSwipeImage;
	is.shortLeftSwipeImage = shortLeftSwipeImage;
	is.longLeftSwipeImage = longLeftSwipeImage;
	return is;
}

/* -------------- SwipeCellColorSet -------------- */
@interface SwipeCellColorSet : NSObject
@property (nonatomic, strong) UIColor *shortRightSwipeColor;
@property (nonatomic, strong) UIColor *longRightSwipeColor;
@property (nonatomic, strong) UIColor *shortLeftSwipeColor;
@property (nonatomic, strong) UIColor *longLeftSwipeColor;
@end

/**
 Use this method to set `JZSwipeCell`'s `colorSet` property.
 @param shortRightSwipeColor The background color to display during a short swipe to the right
 @param longRightSwipeColor The background color to display during a long swipe to the right
 @param shortLeftSwipeColor The background color to display during a short swipe to the left
 @param longLeftSwipeColor The background color to display during a long swipe to the left
 */
NS_INLINE SwipeCellColorSet* SwipeCellColorSetMake(UIColor *shortRightSwipeColor, UIColor *longRightSwipeColor, UIColor *shortLeftSwipeColor, UIColor *longLeftSwipeColor)
{
	SwipeCellColorSet *cs = [[SwipeCellColorSet alloc] init];
	cs.shortRightSwipeColor = shortRightSwipeColor;
	cs.longRightSwipeColor = longRightSwipeColor;
	cs.shortLeftSwipeColor = shortLeftSwipeColor;
	cs.longLeftSwipeColor = longLeftSwipeColor;
	return cs;
}

/* -------------- JZSwipeCell -------------- */

/**
 The 5 available types of swipes.
 @discussion `JZSwipeTypeShortRight`, `JZSwipeTypeLongRight`, `JZSwipeTypeShortLeft` and `JZSwipeTypeLongLeft` are all active swipe types. `JZSwipeTypeNone` is an inactive swipe type and does not trigger an animation which causes the `contentView` to slide off screen.
 */
typedef enum {
	JZSwipeTypeNone,
	JZSwipeTypeShortRight,
	JZSwipeTypeLongRight,
	JZSwipeTypeShortLeft,
	JZSwipeTypeLongLeft
} JZSwipeType;

@class JZSwipeCell;

/**
 The `JZSwipeCellDelegate` defines the message sent to a swipe cell delegate when a swipe is detected.
 */
@protocol JZSwipeCellDelegate <NSObject>

/**
 Notifies the delegate that a swipe of a particular type was detected in a cell
 @param cell The `JZSwipeCell` the swipe was detected in. Use `UITableView`'s `-indexPathForCell:` method to find the `NSIndexPath` for the cell.
 @param swipeType The type of swipe detected in the cell.
 */
- (void)swipeCell:(JZSwipeCell*)cell triggeredSwipeWithType:(JZSwipeType)swipeType;

/**
 Notifies the delegate that a swipe has been restored to its original position.
 @param cell The `JZSwipeCell` the swipe was detected in. Use `UITableView`'s `-indexPathForCell:` method to find the `NSIndexPath` for the cell.
 @param The indicator wether the cell was restored with or without animation
 @author Paul Peelen <Paul@PaulPeelen.com>
 */
- (void)swipeCell:(JZSwipeCell*)cell didRestoreSwipeAmimated:(BOOL)animated;

@optional

/**
 Notifies the delegate that the content view transitioned from one swipe zone to another
 @param cell The `JZSwipeCell` the swipe was detected in. Use `UITableView`'s `-indexPathForCell:` method to find the `NSIndexPath` for the cell.
 @param from The `JZSwipeType` the cell transitioned from
 @param to The `JZSwipeType` the cell transitioned to
 */
- (void)swipeCell:(JZSwipeCell *)cell swipeTypeChangedFrom:(JZSwipeType)from to:(JZSwipeType)to;

@end

@interface JZSwipeCell : UITableViewCell <UIGestureRecognizerDelegate>

/**
 The main view that slides horizontally when a gesture is detected. All subviews should be added to this view.
 */
@property (nonatomic, strong) IBOutlet UIView *contentView;

/**
 The image view in which the icons are displayed.
 @discussion Default size is 40x40 which is changable via it's frame.size property. The frame.origin is irrelevant as the icon will vertically center automatically.
 */
@property (nonatomic, strong) IBOutlet UIImageView *icon;

/**
 The horizontal width of the swipe zone before it becomes a long swipe.
 @discussion Default is 2/3 of the cell's width
 */
@property (nonatomic, assign) CGFloat shortSwipeLength;

/**
 The set of 4 icons that will be used for the 4 swipe zones
 */
@property (nonatomic, strong) SwipeCellImageSet *imageSet;

/**
 The set of 4 colors that will be used for the 4 swipe zones
 */
@property (nonatomic, strong) SwipeCellColorSet *colorSet;

/**
 The background color during a swipe while the swipe has not entered any of the swipe zones
 */
@property (nonatomic, strong) UIColor *defaultBackgroundColor;

/**
 The receiver's delegate.
 @discussion A JZSwipeCell's delegate receives messages when any of the 4 actionable swipe types have been triggered.
 */
@property (nonatomic, assign) id<JZSwipeCellDelegate> delegate;

/**
 The UIGestureRecognizer which JZSwipeCell can recognize.
 */
@property (nonatomic, strong) UIPanGestureRecognizer *gesture;

/**
 Manually trigger a swipe animation followed by a message send to the cell's delegate.
 @param type The type of swipe you would like the cell to trigger.
 */
- (void)triggerSwipeWithType:(JZSwipeType)type;

/**
 Restore the cell to its original position
 @param animated BOOL If the restoration should be animated
 @param animated CGFloat The duration of the delay before animating the restoration
 @author Paul Peelen <Paul@PaulPeelen.com>
 */
- (void)restoreCell:(BOOL)animated delay:(CGFloat)delay;

@end
