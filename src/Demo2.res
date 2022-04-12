// Arbitrary JS Object Type.
// This can be manually defined if desired
type recordProp<'eventWithTime>

// The result of calling `rrweb.record`
// "The record method returns a function which can be called to stop events from firing"
// https://github.com/rrweb-io/rrweb/blob/master/guide.md#getting-started
type stopFn = unit => unit

// Format taken from your provided example
type callback<'eventWithTime> = 'eventWithTime => unit

// https://github.com/rrweb-io/rrweb/blob/master/guide.md#options
// Creates a function `recordProp` that creates objects of type `recordProp`'
// This could be named differently
@obj
external recordProp: (
  ~emit: callback<'eventWithTime>,
  ~checkoutEveryNth: 'a=?,
  ~checkoutEveryNms: 'b=?,
  ~blockClass: 'c=?,
  ~blockSelector: 'd=?,
  ~ignoreClass: 'e=?,
  ~maskTextClass: 'f=?,
  ~maskTextSelector: 'g=?,
  ~maskAllInputs: 'h=?,
  ~maskInputOptions: 'i=?,
  ~maskInputFn: 'j=?,
  ~maskTextFn: 'k=?,
  ~slimDOMOptions: 'l=?,
  ~inlineStylesheet: 'm=?,
  ~hooks: 'n=?,
  ~packFn: 'o=?,
  ~sampling: 'p=?,
  ~recordCanvas: 'q=?,
  ~inlineImages: 'r=?,
  ~collectFonts: 's=?,
  ~userTriggeredOnInput: 't=?,
  ~plugins: 'u=?,
  unit,
) => recordProp<'eventWithTime> = ""

// https://github.com/rrweb-io/rrweb/blob/master/guide.md#getting-started
@module("rrweb")
external record: recordProp<'eventWithTime> => stopFn = "record"
type event =
  | DomContentLoadedEvent
  | LoadedEvent
  | FullSnapshotEvent
  | IncrementalSnapshotEvent
  | MetaEvent
  | CustomEvent
  | PluginEvent

type eventWithTime = {
  event: event,
  timestamp: int,
  delay: option<int>,
}
let events: array<eventWithTime> = []
// Example of creating a record prop with only `emit` defined
// Trailing () arguments are requred for `recordProp` to tell the compiler that is
// is done recieving optional arguments
let stopFn1 = record(recordProp(~emit=a => {
    let _ = Js.Array2.push(events, a)
    Js.log2("events: ", events)
    Js.log(a)
  }, ()))

// Example of creating a record prop with `emit` and something else defined
let stopFn2 = record(recordProp(~emit=a => {
    let _ = Js.Array2.push(events, a)
    Js.log2("events: ", events)
    Js.log(a)
  }, ~ignoreClass=true, ()))

stopFn1()
stopFn2()
// type play<'events> = {play: 'events => unit}
// type replayer<'events> = {
//   events: 'events,
//   play: play<'events>,
// }
type play = { @this play: unit => unit}
// @obj
// external replayerOptions: (~events: 'eventWithTime, unit) => replayer<'events> = ""
// @new because its a class
// @module("rrweb") @new
// external replayer: ('events, unit) => play = "Replayer"

// type rp
// @module("rrweb") @new external rp: rp = "Replayer"
// @set external play: (rp, @this (rp, array<event>) => unit) => unit = "play"
// // @get external resp: x => int = "response"
// play(rp, @this (events,o) => Js.log((events,o)))
// let replayer = replayer(events, ())

// replayer.play()
// type rp
@new @module("rrweb") external mkSolver: (~events:array<'a>,unit) => play = "Replayer"
@set external play: (play, @this (play, array<event>) => unit) => unit = "play"
let replayer = mkSolver(~events, ())
// replayer.play()
Js.log2("replayer",replayer)
 replayer.play()
// let _ =play(replayer)
// type x
// @module("rrweb") @new external x: x = "Replayer"
// @set external setOnload: (x, @this (x, int) => unit) => unit = "play"
// @get external resp: x => int = "response"
// setOnload(x, @this (o, v) => Js.log(resp(o) + v))
// let startReplay = () => {
//   // e->ReactEvent.Mouse.preventDefault;
//   if events->Js.Array.length < 1 {
//     Js.log2(events->Js.Array.length, "it needs more than 2 events to play")
//   } else {
//     let replayer = replayer(events, ())

//     replayer.play()
//   }
// }
// startReplay()
@react.component
let default = () => {
  <div> <h1> {React.string("hello world and stuff yay")} </h1> </div>
}
