//
//  WDThumbnailView.h
//  Inkpad
//
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
//  Copyright (c) 2008-2013 Steve Sprang
//

#import <UIKit/UIKit.h>

@class WDImageView;

@interface WDThumbnailView : UICollectionViewCell <UITextFieldDelegate> {
    UIImageView                 *selectedIndicator_;
    UIActivityIndicatorView     *activityView_;
    UIButton                    *titleLabel_;
}

@property (nonatomic, strong) NSString *filename;
@property (nonatomic, weak) id delegate;
@property (nonatomic, readonly) UITextField *titleField;
@property (nonatomic, readonly) WDImageView *imageView;
@property (nonatomic, assign) BOOL shouldShowSelectionIndicator;

@property (weak, nonatomic) IBOutlet UIView *actionView;
@property (weak, nonatomic) IBOutlet UIButton *duplicatePlanButton;
@property (weak, nonatomic) IBOutlet UIButton *sharePlanButton;
@property (weak, nonatomic) IBOutlet UIButton *deletePlanButton;

// actions:
- (void)showActions;
- (void)hideActions;
- (IBAction)copyTapped:(id)sender;
- (IBAction)shareTapped:(id)sender;
- (IBAction)renameTapped:(id)sender;
- (IBAction)deleteTapped:(id)sender;

// image management
- (void) reload;

- (void) stopEditing;

- (NSComparisonResult) compare:(WDThumbnailView *)thumbView;

- (void) startActivity;
- (void) stopActivity;

@end

@protocol WDThumbnailViewDelegate <NSObject>
- (BOOL) thumbnailShouldBeginEditing:(WDThumbnailView *)thumb;
- (void) thumbnailDidBeginEditing:(WDThumbnailView *)thumb;
- (void) thumbnailDidEndEditing:(WDThumbnailView *)thumb;
- (void) duplicateTapped:(WDThumbnailView *)thumb;
@end
