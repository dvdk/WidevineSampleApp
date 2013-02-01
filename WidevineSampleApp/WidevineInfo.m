//
//  WidevineInfo.m
//  WidevinePlugin
//
//  Created by David McGaffin on 9/26/12.
//
//

#import "WViPhoneAPI.h"
#import "BCVideo.h"
#import "BCEvent.h"
#import "BCWidevinePlugin.h"

#import "WidevineInfo.h"

@implementation WidevineInfo

@synthesize widevinePlugin;
@synthesize widevineInfoView;
@synthesize videoCell = _videoCell;
@synthesize tableView = _tableView;

- (id)init
{
    [super dealloc];
    return nil;
}

- (id)initWithEventEmitter:(BCEventEmitter *)eventEmitter
                    plugin:(BCWidevinePlugin *)plugin
{
    if (self = [super initWithEventEmitter:eventEmitter]) {
        [[NSBundle mainBundle] loadNibNamed:@"WidevineInfo_iphone" owner:self options:nil];
        
        self.widevinePlugin = plugin;
    }
    
    return self;
}

- (void)dealloc
{
    self.widevineInfoView = nil;
    self.widevinePlugin = nil;
    
    [super dealloc];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.widevinePlugin.playlist.videos count];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 80;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
	// Try to retrieve from the table view a now-unused cell with the given identifier.
	VideoViewCell *cell = (VideoViewCell *)[tableView dequeueReusableCellWithIdentifier:[VideoViewCell reuseIdentifier]];
	
	// If no cell is available, create a new one using the given identifier.
	if (cell == nil) {
        [[NSBundle mainBundle] loadNibNamed:@"VideoViewCell" owner:self options:nil];
        cell = _videoCell;
        _videoCell = nil;
	}
	
	// Set up the cell.
	BCVideo *video = [self.widevinePlugin.playlist.videos objectAtIndex:indexPath.row];
    NSURL *stillUrl = [video.properties objectForKey:@"videoStillURL"];
    NSData *imageData = [NSData dataWithContentsOfURL:stillUrl];
    cell.videoStill.image = [UIImage imageWithData:imageData];
	cell.videoNameLabel.text = [video.properties objectForKey:@"name"];
    cell.durationLabel.text = [self hmsForDuration:[video.properties objectForKey:@"duration"]];
	
	return cell;
}

- (NSString *)hmsForDuration:(NSNumber *)duration
{
    unsigned long seconds = duration.unsignedLongValue / 1000;
    NSUInteger h = seconds / 3600;
    NSUInteger m = (seconds / 60) % 60;
    NSUInteger s = (seconds % 60);
    
    return [NSString stringWithFormat:@"%u:%02u:%02u", h, m, s];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    BCVideo *video = [self.widevinePlugin.playlist.videos objectAtIndex:indexPath.row];
    
    self.widevinePlugin.autoPlay = YES;
    [self.widevinePlugin queueVideo:video];
}

@end
