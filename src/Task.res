module Styles = {
  open Css

  let btn = style(list{
    display(#flex),
    alignItems(#center),
    justifyContent(#center),
    margin2(~v=#zero, ~h=#auto),
    fontSize(px(10)),
    border(1->px, solid, #var("--grey-9-rgb")),
    marginTop(px(10)),
    height(px(30)),
  })
  //        fontSize(`10px);
  //   border: 1px solid rgb(var(--grey-9-rgb));
  //   margin-top: 10px;
  //   height: 30px;
}

type event
type emit<'eventWithTime> = {emit: 'eventWithTime => unit}

let events: array<event> = []

// type replayerOptions;
// type replayer = {play: unit => unit};
// // [@obj] external replayerOptions: (~events: 'a, unit) => replayerOptions;

// [@module "rrweb"] [@new] external replayer: replayer = "Replayer";
type replayerOptions
type replayer = {play: unit => unit}
@obj external replayerOptions: (~events: 'a, unit) => replayerOptions = ""

@module("rrweb") 
external replayer: replayerOptions => replayer = "Replayer"
type rrweb<'a> = {
  // emit: 'a => unit,
  record: 'a => unit,
  @as("Replayer")
  replayer: 'a => replayer,
}
@module external rrweb: rrweb<'a> = "rrweb"

rrweb.record({
  emit: event => {
    let _ = Js.Array2.push(events, event)
    Js.log2(events, "events")
  },
})
// rrweb.replayer({
//   play: events =>
//     (
//       () => {
//         Js.log2(events, "events");
//       }
//     )(),
// });

@react.component
let make = () =>
  <div>
    <button
      onClick={_ => {
        let stopFn = () =>
          rrweb.record({
            emit: () => Js.log("emmitting"),
          })
        stopFn()
      }}
      className=Styles.btn>
      {"Stop record"->React.string}
    </button>
    <button
      className=Styles.btn
      onClick={_ => {
        let replayer = rrweb.replayer(replayerOptions(~events, ()))
        Js.log2("replayer:", replayer)
        replayer.play()
      }}>
      {"Replay"->React.string}
    </button>
  </div>
let default = make
