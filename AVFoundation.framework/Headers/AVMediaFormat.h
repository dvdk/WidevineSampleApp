/*
    File:  AVMediaFormat.h

	Framework:  AVFoundation
 
	Copyright 2010-2012 Apple Inc. All rights reserved.

*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

// Media types

AVF_EXPORT NSString *const AVMediaTypeVideo                 NS_AVAILABLE(10_7, 4_0);
AVF_EXPORT NSString *const AVMediaTypeAudio                 NS_AVAILABLE(10_7, 4_0);
AVF_EXPORT NSString *const AVMediaTypeText                  NS_AVAILABLE(10_7, 4_0);
AVF_EXPORT NSString *const AVMediaTypeClosedCaption         NS_AVAILABLE(10_7, 4_0);
AVF_EXPORT NSString *const AVMediaTypeSubtitle              NS_AVAILABLE(10_7, 4_0);
AVF_EXPORT NSString *const AVMediaTypeTimecode              NS_AVAILABLE(10_7, 4_0);
AVF_EXPORT NSString *const AVMediaTypeMetadata              NS_AVAILABLE(10_8, 6_0);
AVF_EXPORT NSString *const AVMediaTypeMuxed                 NS_AVAILABLE(10_7, 4_0);


// Media characteristics

/*!
 @constant AVMediaCharacteristicVisual
 @abstract A media characteristic that indicates that a track or media selection option includes visual content.
 @discussion
 AVMediaTypeVideo, AVMediaTypeSubtitle, AVMediaTypeClosedCaption are examples of media types with the characteristic AVMediaCharacteristicVisual.
 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicVisual      NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVMediaCharacteristicAudible
 @abstract A media characteristic that indicates that a track or media selection option includes audible content.
 @discussion
 AVMediaTypeAudio is a media type with the characteristic AVMediaCharacteristicAudible.
 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicAudible     NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVMediaCharacteristicLegible
 @abstract A media characteristic that indicates that a track or media selection option includes legible content.
 @discussion
 AVMediaTypeSubtitle and AVMediaTypeClosedCaption are examples of media types with the characteristic AVMediaCharacteristicLegible.
 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicLegible     NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVMediaCharacteristicFrameBased
 @abstract A media characteristic that indicates that a track or media selection option includes content that's frame-based.
 @discussion
 Frame-based content typically comprises discrete media samples that, once rendered, can remain current for indefinite periods of time without additional processing in support of "time-stretching". Further, any dependencies between samples are always explicitly signalled, so that the operations required to render any single sample can readily be performed on demand. AVMediaTypeVideo is the most common type of frame-based media. AVMediaTypeAudio is the most common counterexample. 
 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicFrameBased  NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVMediaCharacteristicIsMainProgramContent
 @abstract A media characteristic that indicates that a track or media selection option includes content that's marked by the content author as intrinsic to the presentation of the asset.
 @discussion
 Example: an option that presents the main program audio for the presentation, regardless of locale, would typically have this characteristic.
 The value of this characteristic is @"public.main-program-content".
 Note for content authors: the presence of this characteristic for a media option is inferred; any option that does not have the characteristic AVMediaCharacteristicIsAuxiliaryContent is considered to have the characteristic AVMediaCharacteristicIsMainProgramContent.

 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicIsMainProgramContent NS_AVAILABLE(10_8, 5_0);

/*!
 @constant AVMediaCharacteristicIsAuxiliaryContent
 @abstract A media characteristic that indicates that a track or media selection option includes content that's marked by the content author as auxiliary to the presentation of the asset.
 @discussion
 The value of this characteristic is @"public.auxiliary-content".
 Example: an option that presents audio media containing commentary on the presentation would typically have this characteristic.
 Note for content authors: for QuickTime movie and .m4v files a media option is considered to have the characteristic AVMediaCharacteristicIsAuxiliaryContent if it's explicitly tagged with that characteristic or if, as a member of an altenate track group, its associated track is excluded from autoselection.
 See the discussion of the tagging of tracks with media characteristics below.

 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicIsAuxiliaryContent NS_AVAILABLE(10_8, 5_0);

/*!
 @constant AVMediaCharacteristicContainsOnlyForcedSubtitles
 @abstract A media characteristic that indicates that a track or media selection option presents only forced subtitles.
 @discussion
 Media options with forced-only subtitles are typically selected when 1) the user has not selected a legible option with an accessibility characteristic or an auxiliary purpose and 2) its locale matches the locale of the selected audible media selection option.
 The value of this characteristic is @"public.subtitles.forced-only".
 Note for content authors: the presence of this characteristic for a legible media option is inferred from the format description of the associated track that presents the subtitle media.

 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicContainsOnlyForcedSubtitles NS_AVAILABLE(10_8, 5_0);

/*!
 @constant AVMediaCharacteristicTranscribesSpokenDialogForAccessibility
 @abstract A media characteristic that indicates that a track or media selection option includes legible content in the language of its specified locale that:
 	- transcribes spoken dialog and
 	- identifies speakers whenever other visual cues are insufficient for a viewer to determine who is speaking.
 @discussion
 Legible tracks provided for accessibility purposes are typically tagged both with this characteristic as well as with AVMediaCharacteristicDescribesMusicAndSoundForAccessibility.

 A legible track provided for accessibility purposes that's associated with an audio track that has no spoken dialog can be tagged with this characteristic, because it trivially meets these requirements.

 The value of this characteristic is @"public.accessibility.transcribes-spoken-dialog".

 Note for content authors: for QuickTime movie and .m4v files a media option is considered to have the characteristic AVMediaCharacteristicTranscribesSpokenDialogForAccessibility only if it's explicitly tagged with that characteristic.
 See the discussion of the tagging of tracks with media characteristics below.

 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicTranscribesSpokenDialogForAccessibility NS_AVAILABLE(10_8, 5_0);

/*!
 @constant AVMediaCharacteristicDescribesMusicAndSoundForAccessibility
 @abstract A media characteristic that indicates that a track or media selection option includes legible content in the language of its specified locale that:
 	- describes music and
 	- describes sound other than spoken dialog, such as sound effects and significant silences, occurring in program audio.
 @discussion
 Legible tracks provided for accessibility purposes are typically tagged both with this characteristic as well as with AVMediaCharacteristicTranscribesSpokenDialogForAccessibility.

 A legible track provided for accessibility purposes that's associated with an audio track without music and without sound other than spoken dialog -- lacking even significant silences -- can be tagged with this characteristic, because it trivially meets these requirements.

 The value of this characteristic is @"public.accessibility.describes-music-and-sound".

 Note for content authors: for QuickTime movie and .m4v files a media option is considered to have the characteristic AVMediaCharacteristicDescribesMusicAndSoundForAccessibility only if it's explicitly tagged with that characteristic.
 See the discussion of the tagging of tracks with media characteristics below.

 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicDescribesMusicAndSoundForAccessibility NS_AVAILABLE(10_8, 5_0);

/*!
 @constant AVMediaCharacteristicEasyToRead
 @abstract A media characteristic that indicates that a track or media selection option provides legible content in the language of its specified locale that has been edited for ease of reading.
 @discussion
 The value of this characteristic is @"public.easy-to-read".
 
 Closed caption tracks that carry "easy reader" captions (per the CEA-608 specification) should be tagged with this characteristic. Subtitle tracks can also be tagged with this characteristic, where appropriate.

 Note for content authors: for QuickTime movie and .m4v files a track is considered to have the characteristic AVMediaCharacteristicEasyToRead only if it's explicitly tagged with that characteristic.
 See the discussion of the tagging of tracks with media characteristics below.

 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicEasyToRead NS_AVAILABLE(10_8, 6_0);

/*!
 @constant AVMediaCharacteristicDescribesVideoForAccessibility
 @abstract A media characteristic that indicates that a track or media selection option includes audible descriptions of the visual portion of the presentation that are sufficient for listeners without access to the visual content to comprehend the essential information, such as action and setting, that it depicts.
 @discussion
 See -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
 The value of this characteristic is @"public.accessibility.describes-video".
 Note for content authors: for QuickTime movie and .m4v files a media option is considered to have the characteristic AVMediaCharacteristicDescribesVideoForAccessibility only if it's explicitly tagged with that characteristic.
 See the discussion of the tagging of tracks with media characteristics below.

 Also see -[AVAssetTrack hasMediaCharacteristic:] and -[AVMediaSelectionOption hasMediaCharacteristic:].
*/
AVF_EXPORT NSString *const AVMediaCharacteristicDescribesVideoForAccessibility NS_AVAILABLE(10_8, 5_0);

/*
	Tagging of tracks of .mov and .m4v files with media characteristics

	Each track of .mov files and .m4v files (that is, files of type AVFileTypeQuickTimeMovie and AVFileTypeAppleM4V) can optionally carry one or more tagged media characteristics, each of which declares a purpose, a trait, or some other disinguishing property of the track's media.

	For example, a track containing audio that mixes original program content with additional narrative descriptions of visual action may be tagged with the media characteristic "public.accessibility.describes-video" in order to distinguish it from other audio tracks stored in the same file that do not contain additional narrative. 

	Each tagged media characteristic in .mov and .m4v files is stored in track userdata as a userdata item of type 'tagc' (represented as a FourCharCode) that consists of a standard atom header (size and type) followed by an array of US-ASCII characters (8-bit, high bit clear) comprising the value of the tag. The character array is not a C string; there is no terminating zero. The userdata item atom size is sum of the standard atom header size (8) and the size of the US-ASCII character array.

	AVFoundation clients can inspect the tagged media characteristics of a track as follows:

		NSArray *trackUserDataItems = [myAVAssetTrack metadataForFormat:AVMetadataFormatQuickTimeUserData];
		NSArray *trackTaggedMediaCharacteristics = [AVMetadataItem metadataItemsFromArray:trackUserDataItems withKey:AVMetadataQuickTimeUserDataKeyTaggedCharacteristic keySpace:AVMetadataKeySpaceQuickTimeUserData];

		for (AVMetadataItem *metadataItem in trackTaggedMediaCharacteristics) {
			NSString *thisTrackMediaCharacteristic = [metadataItem stringValue];
		}

	-[AVAssetTrack hasMediaCharacteristic:] can be used to determine whether a track has a particular media characteristic, whether the characteristic is inferred from its media type or format descriptions (e.g. AVMediaCharacteristicAudible, AVMediaCharacteristicContainsOnlyForcedSubtitles) or requires explicit tagging (e.g. AVMediaCharacteristicTranscribesSpokenDialogForAccessibility, AVMediaCharacteristicDescribesVideoForAccessibility). Note that explicit tagging can't be used to override inferences from tracks' media types or format descriptions; for example, -[AVAssetTrack hasMediaCharacteristic:AVMediaCharacteristicVisual] will return NO for any audio track, even if the track has been perversely tagged with the visual characteristic.

	Tagged media characteristics can be written to the QuickTime userdata of an output track associated with an AVAssetWriterInput as follows, provided that the outputFileType of the AVAssetWriter is either AVFileTypeQuickTimeMovie or AVFileTypeAppleM4V:

		AVMutableMetadataItem *myTaggedMediaCharacteristic = [[[AVMutableMetadataItem alloc] init] autorelease];

		[myTaggedMediaCharacteristic setKey:AVMetadataQuickTimeUserDataKeyTaggedCharacteristic];
		[myTaggedMediaCharacteristic setKeySpace:AVMetadataKeySpaceQuickTimeUserData];

		[myTaggedMediaCharacteristic setValue:aMeaningfulCharacteristicAsNSString];

		[myMutableArrayOfMetadata addObject:myTaggedMediaCharacteristic];

		[myAssetWriterInput setMetadata:myMutableArrayOfMetadata];

*/

// File format UTIs

/*!
 @constant AVFileTypeQuickTimeMovie
 @abstract A UTI for the QuickTime movie file format.
 @discussion
 The value of this UTI is @"com.apple.quicktime-movie".
 Files are identified with the .mov and .qt extensions.
 */
AVF_EXPORT NSString *const AVFileTypeQuickTimeMovie NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeMPEG4
 @abstract A UTI for the MPEG-4 file format.
 @discussion
 The value of this UTI is @"public.mpeg-4".
 Files are identified with the .mp4 extension.
 */
AVF_EXPORT NSString *const AVFileTypeMPEG4 NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeAppleM4V
 @discussion
 The value of this UTI is @"com.apple.m4v-video".
 Files are identified with the .m4v extension.
 */
AVF_EXPORT NSString *const AVFileTypeAppleM4V NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeAppleM4A
 @discussion
 The value of this UTI is @"com.apple.m4a-audio".
 Files are identified with the .m4a extension.
 */
AVF_EXPORT NSString *const AVFileTypeAppleM4A NS_AVAILABLE(10_7, 4_0);

#if TARGET_OS_IPHONE

/*!
 @constant AVFileType3GPP
 @abstract A UTI for the 3GPP file format.
 @discussion
 The value of this UTI is @"public.3gp".
 Files are identified with the .3gp, .3gpp, and .sdv extensions.
 */
AVF_EXPORT NSString *const AVFileType3GPP NS_AVAILABLE_IOS(4_0);

#endif // TARGET_OS_IPHONE

/*!
 @constant AVFileTypeCoreAudioFormat
 @abstract A UTI for the CoreAudio file format.
 @discussion
 The value of this UTI is @"com.apple.coreaudio-format".
 Files are identified with the .caf extension.
 */
AVF_EXPORT NSString *const AVFileTypeCoreAudioFormat NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeWAVE
 @abstract A UTI for the WAVE audio file format.
 @discussion
 The value of this UTI is @"com.microsoft.waveform-audio".
 Files are identified with the .wav, .wave, and .bwf extensions.
 */
AVF_EXPORT NSString *const AVFileTypeWAVE NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeAIFF
 @abstract A UTI for the AIFF audio file format.
 @discussion
 The value of this UTI is @"public.aiff-audio".
 Files are identified with the .aif and .aiff extensions.
 */
AVF_EXPORT NSString *const AVFileTypeAIFF NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeAIFC
 @abstract A UTI for the AIFC audio file format.
 @discussion
 The value of this UTI is @"public.aifc-audio".
 Files are identified with the .aifc and .cdda extensions.
 */
AVF_EXPORT NSString *const AVFileTypeAIFC NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeAMR
 @abstract A UTI for the adaptive multi-rate audio file format.
 @discussion
 The value of this UTI is @"org.3gpp.adaptive-multi-rate-audio".
 Files are identified with the .amr extension.
 */
AVF_EXPORT NSString *const AVFileTypeAMR NS_AVAILABLE(10_7, 4_0);
