type callback('a) = 'a => unit;
type listenerHandler = unit => unit;
type observer('a, 'TOptions) =
  (~cb: callback('a), ~options: 'TOptions, unit) => unit;
// type recordPlugin('a, 'TOptions) = {
//   name: string,
//   observer: option((~cb: callback('a), ~options: 'TOptions, unit) => unit),
//   options: 'TOptions,
// };

type t;

[@obj]
external make:
  (
    ~name: string,
    ~observer: (~cb: callback('a), ~options: 'TOptions, unit) => unit=?,
    ~options: 'TOptions,
    unit
  ) =>
  t;

let exampleRecordPlugin: t =
  make(
    ~name="my-scope/example@1",
    ~observer=
      (~cb: 'a => unit, ~options) => {
        let timer =
          Js.Global.setInterval(
            () => {cb({"foo": options##foo, "timestamp": Js.Date.now()})},
            1000,
          );
        () => Js.Global.clearInterval(timer);
      },
    ~options={"foo": "bar"},
    (),
  );
// type tExtend('a) = (~event:EventWithTime.t) =>{event:event, tExtend: 'a };
// type eventProcessor('a, 'e) = EventWithTime.t =>{ event:e,tExtend: tExtend('a)}=> unit;
// type RecordPlugin<TOptions = unknown> = {
//   name: string;
//   observer?: (cb: Function, win: IWindow, options: TOptions) => listenerHandler;
//   eventProcessor?: <TExtend>(event: eventWithTime) => eventWithTime & TExtend;
//   options: TOptions;
