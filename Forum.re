/* Define this in Rrweb.res rather than in file */
module Rrweb = {
  /* Contains things related to the event type */
  module EventWithTime = {
    type nonrec t('a) = {event: 'a};

    /* Equivalent to %identity type conversion, unsafe, only for demonstration*/
    let make = (any: 'a): t('a) => {event: any};
  };

  module Record = {
    type nonrec options;

    type nonrec callback('a) = EventWithTime.t('a) => unit;

    /* The result of calling `rrweb.record`*/
    /* "The record method returns a function which can be called to stop events from firing"*/
    /* https://github.com/rrweb-io/rrweb/blob/master/guide.md#getting-started*/
    type nonrec stopFn = unit => unit;

    [@obj]
    external mkOptions:
      (
        ~emit: callback('a),
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
        unit
      ) =>
      options;

    /* https://github.com/rrweb-io/rrweb/blob/master/guide.md#getting-started*/
    [@module "rrweb"] external record: options => stopFn = "record";
  } /* Contains things related only to the Replayer */;

  module Replayer = {
    /* Stand in type for the Replayer class objects*/
    type nonrec t;

    /* Stand in type for the optional options record for the Replayer constructor*/
    type nonrec options;

    [@obj]
    /*   ~events: array<EventWithTime.t<'a>>,*/
    external mkOptions:
      (
        ~speed: float=?,
        /* And all the other options [here](https://github.com/rrweb-io/rrweb/blob/master/guide.md#options-1)*/
        /* Didn't want to type them this time*/
        unit
      ) =>
      options /* Create the Replayer object */;

    [@module "rrweb"] [@new]
    external make: array(EventWithTime.t('a)) => t = "Replayer" /* Create the Replayer object */;

    [@module "rrweb"] [@new]
    external makeWithOptions: (array(EventWithTime.t('a)), options) => t =
      "Replayer" /* Use @send to equivalently do Replayer.someFunc */;

    [@send] external play: t => unit = "play";
  };
};

/* Usage*/

/* Optionally open the bindings to avoid typeing Rrweb a lot*/

/* Example of creating a record prop with only `emit` defined*/
/* Trailing () arguments are requred for `recordProp` to tell the compiler that is*/
/* is done recieving optional arguments*/
let stopFn = Record.record(Record.mkOptions(~emit=a => Js.log(a), ()));

stopFn() /* Fake events */;

let events: array(EventWithTime.t('a)) = [|
  EventWithTime.make("some"),
  EventWithTime.make("event"),
|];
Js.log2("events", events) /* Create the replayer object with the given events */;
let replayer = Replayer.make(events) /* Create the replayer object with the given events *and* options */;

let replayerWithOptions =
  Replayer.makeWithOptions(
    events,
    Replayer.mkOptions(~speed=2.0, ()),
  ) /* Compiles to replayer.play() */;

replayer->Replayer.play;
[@react.component]
let default = () => <div> <h1> {React.string("rrweb")} </h1> </div>;
