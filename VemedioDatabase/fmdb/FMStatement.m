//
//  FMStatement.m
//  VemedioDatabase
//
//  Created by Martin Hering on 13.01.16.
//  Copyright © 2016 Vemedio. All rights reserved.
//

#import "FMStatement.h"
#import "FMMacros.h"

@implementation FMStatement  {
    sqlite3_stmt *_statement;
    NSString *_query;
    long _useCount;
    BOOL _inUse;
}

@synthesize statement=_statement;
@synthesize query=_query;
@synthesize useCount=_useCount;
@synthesize inUse=_inUse;

- (void)finalize {
    [self close];
    [super finalize];
}

- (void)dealloc {
    [self close];
    FMDBRelease(_query);
#if ! __has_feature(objc_arc)
    [super dealloc];
#endif
}

- (void)close {
    if (_statement) {
        sqlite3_finalize(_statement);
        _statement = 0x00;
    }

    _inUse = NO;
}

- (void)reset {
    if (_statement) {
        sqlite3_reset(_statement);
    }

    _inUse = NO;
}

- (NSString*)description {
    return [NSString stringWithFormat:@"%@ %ld hit(s) for query %@", [super description], _useCount, _query];
}


@end
