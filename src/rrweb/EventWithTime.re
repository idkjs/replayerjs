type event =
  | DomContentLoadedEvent
  | LoadedEvent
  | FullSnapshotEvent
  | IncrementalSnapshotEvent
  | MetaEvent
  | CustomEvent
  | PluginEvent;

type t;
[@obj]
external make:
  (~event: event, ~timestamp: float=?, ~delay: float=?, unit) => t;