import { Observable, EventData, Page } from '@nativescript/core';
import { DemoSharedV8ModuleCpp } from '@demo/shared';
import {} from 'v8-module-cpp';

export function navigatingTo(args: EventData) {
  const page = <Page>args.object;
  page.bindingContext = new DemoModel();
}

export class DemoModel extends DemoSharedV8ModuleCpp {}
