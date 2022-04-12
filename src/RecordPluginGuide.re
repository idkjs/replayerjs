open Antd;

module Button = {
  [@react.component]
  let make = (~title, ~onClick) => {
    <Button className=".rr-block" onClick> title->React.string </Button>;
  };
};
let exampleRecordPlugin: RecordPlugin.t =
  RecordPlugin.make(
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

  Record.record(
    Record.recordOptions(
      ~emit=event => Js.log2("emit", event),
      ~plugins=[|exampleRecordPlugin|],
      (),
    ),
    (),
  );
[@react.component]
let make = () => {
  //   Record.record(
  //     Record.recordOptions(
  //       ~emit=event => Js.log2("emit", event),
  //       ~plugins=[|exampleRecordPlugin|],
  //       (),
  //     ),
  //     (),
  //   );
//   Record.record(
//     Record.recordOptions(
//       ~emit=event => Js.log2("emit", event),
//       ~plugins=[|exampleRecordPlugin|],
//       (),
//     ),
//     (),
//   );
  //   let startRecord = () => {
  //     Record.record(
  //       Record.recordOptions(
  //         ~emit=event => Js.log2("emit", event),
  //         ~plugins=[|exampleRecordPlugin|],
  //         (),
  //       ),
  //       (),
  //     );
  //   };
  // //   startRecord();
  //   React.useEffect(() => {
  //     Record.record(
  //       Record.recordOptions(
  //         ~emit=event => Js.log2("emit", event),
  //         ~plugins=[|exampleRecordPlugin|],
  //         (),
  //       ),
  //       (),
  //     );
  //     Some(() => ());
  //   });

  <Layout>
    <Layout.Header>
      <span className=Css.(style([color(white)]))>
        {React.string("RecordPlugin Example")}
      </span>
    </Layout.Header>
    // <Button title="start recording" onClick=startRecord />
    // <Button title="start replay" onClick=startReplay />
    // <Button title="stop recording" onClick=stopRecording />
    // <Button title="start recording" onClick=startRecording />
    // <Layout.Content> <Card> <span className=Css.(style([color(white)]))>
    //     {React.string("RecordPlugin Example")}
    //   </span> </Card> </Layout.Content>
  </Layout>;
};
let default = make;
