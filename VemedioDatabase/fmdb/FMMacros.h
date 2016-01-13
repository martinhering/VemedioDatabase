//
//  FMMacros.h
//  VemedioDatabase
//
//  Created by Martin Hering on 13.01.16.
//  Copyright © 2016 Vemedio. All rights reserved.
//

#ifndef FMMacros_h
#define FMMacros_h

#if ! __has_feature(objc_arc)
#define FMDBAutorelease(__v) ([__v autorelease]);
#define FMDBReturnAutoreleased FMDBAutorelease

#define FMDBRetain(__v) ([__v retain]);
#define FMDBReturnRetained FMDBRetain

#define FMDBRelease(__v) ([__v release]);

#define FMDBDispatchQueueRelease(__v) (dispatch_release(__v));
#else
// -fobjc-arc
#define FMDBAutorelease(__v)
#define FMDBReturnAutoreleased(__v) (__v)

#define FMDBRetain(__v)
#define FMDBReturnRetained(__v) (__v)

#define FMDBRelease(__v)

// If OS_OBJECT_USE_OBJC=1, then the dispatch objects will be treated like ObjC objects
// and will participate in ARC.
// See the section on "Dispatch Queues and Automatic Reference Counting" in "Grand Central Dispatch (GCD) Reference" for details.
#if OS_OBJECT_USE_OBJC
#define FMDBDispatchQueueRelease(__v)
#else
#define FMDBDispatchQueueRelease(__v) (dispatch_release(__v));
#endif
#endif

#if !__has_feature(objc_instancetype)
#define instancetype id
#endif

#endif /* FMMacros_h */
