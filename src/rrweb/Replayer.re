/* Stand in type for the Replayer class objects*/
type t;
// fix this: how to us `@as` in @obj below
type unsafeReplayCanvas = {
  [@as "UNSAFE_replayCanvas"]
  unsafeReplayCanvas: bool,
};

type mousetail;

[@obj]
external moustail:
  (
    ~duration: int=?,
    ~lineCap: string=?,
    ~lineWidth: int=?,
    ~strokeStyle: string=?,
    unit
  ) =>
  mousetail;

type boolOrMouseTail =
  | Bool(bool)
  | Mousetail(mousetail);

type replayPlugin('a) = {
  handler: (~event: 'a, ~isSync: bool, ~context: t) => unit,
};
/* Stand in type for the optional options record for the Replayer constructor*/
// type eventWithTime;
// type options = {
//   speed: int,
//   maxSpeed: int,
//   root: Dom.element,
//   loadTimeout: int,
//   skipInactive: bool,
//   showWarning: bool,
//   showDebug: bool,
//   blockClass: string,
//   liveMode: bool,
//   insertStyleRules: array(string),
//   triggerFocus: bool,
//   [@bs.as "UNSAFE_replayCanvas"]
//   unsafeReplayCanvas: bool,
//   pauseAnimation: bool,
//   mouseTail: MouseTail.t,
//   unpackFn: (~raw: string) => eventWithTime,
//   plugins: array(replayPlugin),
// };
/* All options [here](https://github.com/rrweb-io/rrweb/blob/master/guide.md#options-1)*/
type options;
[@obj]
external recordOptions:
  (
    ~speed: float=?,
    ~root: Dom.element=?, // document.body   the root element of replayer
    ~loadTimeout: float=?, //  0   timeout of loading remote style sheet
    ~skipInactive: bool=?, // false   whether to skip inactive time
    ~showWarning: bool=?, //  true   whether to print warning messages during replay
    ~showDebug: bool=?, //false whether to print debug messages during replay
    ~blockClass: [ | [@as "rr-block"] `rrblock]=?, // 'rr-block'  element with the class name will display as a blocked area
    ~liveMode: bool=?, //  false   whether to enable live mode
    ~insertStyleRules: array(string)=?, // []  accepts multiple CSS rule string, which will be injected into the replay iframe
    ~triggerFocus: float=?, //  true    whether to trigger focus during replay
    ~unsafeReplayCanvas: unsafeReplayCanvas=?, // false   whether to replay the canvas element. Enable this will remove the sandbox, which is unsafe.
    ~mouseTail: boolOrMouseTail=?, // true    whether to show mouse tail during replay. Set to false to disable mouse tail. A complete config can be found in this type
    ~unpackFn: float=?, // -   refer to the storage optimization recipe
    ~logConfig: float=?, // -   configuration of console output playback, refer to the console recipe
    ~plugins: array(replayPlugin('a))=?,
    unit
  ) =>
  options;
/* Create the Replayer object */
[@module "rrweb"] [@new] external make: array('a) => t = "Replayer";
/* Create the Replayer object */
[@module "rrweb"] [@new]
external makeWithOptions: (array('a), options) => t = "Replayer";

type handler('a) = (~event: option('a)) => unit;

type playerMetaData;

[@obj]
external playerMetaData:
  (~startTime: float, ~endTime: float, ~totalTime: float, unit) =>
  playerMetaData;

type rawEvent =
  | RawEvent(EventWithTime.t)
  | Str(string);

type playerConfig;
[@obj]
external playerConfig:
  (
    ~speed: int=?,
    ~maxSpeed: int=?,
    ~root: Dom.element=?,
    ~loadTimeout: int=?,
    ~skipInactive: bool=?,
    ~showWarning: bool=?,
    ~showDebug: bool=?,
    ~blockClass: string,
    ~liveMode: bool=?,
    ~insertStyleRules: array(string)=?,
    ~triggerFocus: bool=?,
    ~unsafeReplayCanvas: unsafeReplayCanvas=?,
    ~pauseAnimation: bool=?,
    ~mouseTail: boolOrMouseTail=?,
    ~unpackFn: (~raw: string) => EventWithTime.t=?,
    ~plugins: array(replayPlugin('a))=?,
    unit
  ) =>
  playerConfig;
[@send] external play: t => unit = "play";
[@send] external addEvent: (t, 'a) => unit = "addEvent";
[@send] external addRawEvent: (t, rawEvent) => unit = "addEvent";
[@send] external on: t => (string, handler('a)) = "on";
[@send] external off: t => (string, handler('a)) = "off";
[@send] external setConfig: (t, ~config: playerConfig) => unit = "setConfig";
[@send] external getMetaData: t => playerMetaData = "getMetaData";
[@send] external getCurrentTime: t => float = "getCurrentTime";
[@send] external getTimeOffset: t => float = "getTimeOffset";
[@send] external getMirror: t => unit = "getMirror";
[@send] external pause: (t, option(float)) => unit = "pause";
[@send] external resume: (t, option(float)) => unit = "resume";
[@send] external startLive: (t, option(float)) => unit = "startLive";
[@send] external enableInteract: t => unit = "enableInteract";
[@send] external disableInteract: t => unit = "disableInteract";
[@send] external resetCache: t => unit = "resetCache";
