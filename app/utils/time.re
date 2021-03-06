open BsLuxon;

let convertToTimezone = (time: float, timezone) =>
  DateTime.(fromMillis(time) |> setZone(timezone));

let convertUnixToTimezone = (epoch: float, timezone) =>
  DateTime.(fromMillis(epoch) |> setZone(timezone));

let convertToString = (format: string) => DateTime.toFormat(format);

let convertToTimezoneAndString = (time, timezone, format) =>
  convertUnixToTimezone(time, timezone) |> DateTime.toFormat(format);

let isAfterCurrent = (epoch: float) =>
  epoch > (DateTime.local() |> DateTime.valueOf());

let isDaylight = (timezone: string) => {
  let time = DateTime.(local() |> setZone(timezone));
  time##hour > 6 && time##hour < 18;
};

let setToTime = (time, h: int) =>
  DateTime.(local(time, ~hour=h) |> startOf(`hour));

let setToStartOf = start => DateTime.startOf(start);
