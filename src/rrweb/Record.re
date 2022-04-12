type options;

type callback('a) = 'a => unit;

/* The result of calling `rrweb.record`*/
/* "The record method returns a function which can be called to stop events from firing"*/
/* https://github.com/rrweb-io/rrweb/blob/master/guide.md#getting-started*/
type stopFn = unit => unit;

type packFn('eventWithTime) = (~event: 'eventWithTime) => string;

type slimDOMOptions;
[@obj]
external slimDOMOptions:
  (
    ~script: bool=?,
    ~comment: bool=?,
    ~headFavicon: bool=?,
    ~headWhitespace: bool=?,
    ~headMetaDescKeywords: bool=?,
    ~headMetaSocial: bool=?,
    ~headMetaRobots: bool=?,
    ~headMetaHttpEquiv: bool=?,
    ~headMetaAuthorship: bool=?,
    ~headMetaVerification: bool=?,
    unit
  ) =>
  slimDOMOptions;

type boolOrSlimDOMOptions =
  | Bool(bool)
  | Mousetail(slimDOMOptions)
  | All([ | `all]);

type dateTimeLocal = {
  [@as "datetime-local"]
  dateTimeLocal: bool,
};
type maskInputOptions;
[@obj]
external maskInputOptions:
  (
    ~color: bool=?,
    ~date: bool=?,
    // TODO: fix this
    ~dateTimeLocal: bool=?,
    ~email: bool=?,
    ~month: bool=?,
    ~number: bool=?,
    ~range: bool=?,
    ~search: bool=?,
    ~tel: bool=?,
    ~text: bool=?,
    ~time: bool=?,
    ~url: bool=?,
    ~week: bool=?,
    unit
  ) =>
  maskInputOptions;

type maskTextFn = (~text: string) => string;

type blockClass =
  | String(string)
  | Regex(Js.Re.t);

type hooksParam;
[@obj]
external hooksParam:
  (
    ~mutation: callback('a)=?,
    ~mousemove: callback('a)=?,
    ~mouseInteraction: callback('a)=?,
    ~scroll: callback('a)=?,
    ~viewportResize: callback('a)=?,
    ~input: callback('a)=?,
    ~mediaInteaction: callback('a)=?,
    ~styleSheetRule: callback('a)=?,
    ~styleDeclaration: callback('a)=?,
    ~canvasMutation: callback('a)=?,
    ~font: callback('a)=?,
    unit
  ) =>
  hooksParam;

[@obj]
external recordOptions:
  (
    ~emit: callback('a),
    ~checkoutEveryNth: 'a=?,
    ~checkoutEveryNms: 'b=?,
    ~blockClass: 'blockClass=?,
    ~blockSelector: Js.Nullable.t(string)=?,
    ~ignoreClass: 'e=?,
    ~maskTextClass: 'f=?,
    ~maskTextSelector: 'g=?,
    ~maskAllInputs: bool=?,
    ~maskInputOptions: maskInputOptions=?,
    ~maskInputFn: 'maskTextFn=?,
    ~maskTextFn: 'maskTextFn=?,
    ~slimDOMOptions: boolOrSlimDOMOptions=?,
    ~inlineStylesheet: bool=?,
    ~hooks: 'hooksParam=?,
    ~packFn: packFn('eventWithTime)=?,
    ~sampling: 'p=?,
    ~recordCanvas: bool=?,
    ~inlineImages: bool=?,
    ~collectFonts: bool=?,
    ~userTriggeredOnInput: bool=?,
    ~plugins: 'u=?,
    unit
  ) =>
  options;

/* https://github.com/rrweb-io/rrweb/blob/master/guide.md#getting-started*/
[@module "rrweb"] external record: options => stopFn = "record";
