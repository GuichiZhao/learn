// var request = require("request");
// var fs = require("fs");

import request from "request";
var options = {
  method: "POST",
  url: "http://bagdb-cn-test.plus.ai:8443/api/v1/jiras/attach",
  headers: {
    accept: "application/json",
  },
  formData: {
    products: "J7+",
    priority: "Lowest",
    summary: "test",
    just_create_issue: "false",
    track: "DevOps",
    assignee: "5e1e5fd10f45160ca25cbc4f",
    is_simulator: "false",
    event_ids: "33766721",
    feature: "Data Engine",
    // attachments: {
    //   value: fs.createReadStream("/home/plusai/Downloads/nvidia.txt"),
    //   options: {
    //     filename: "nvidia.txt",
    //     contentType: null,
    //   },
    // },
    type: "Test",
    description: "test",
    labels: "pilot-test",
    // attachments: {
    //   value: fs.createReadStream("/home/plusai/Downloads/nv_update.sh"),
    //   options: {
    //     filename: "nv_update.sh",
    //     contentType: null,
    //   },
    // },
    // attachments: {
    //   value: fs.createReadStream("/home/plusai/Downloads/latest_version"),
    //   options: {
    //     filename: "latest_version",
    //     contentType: null,
    //   },
    // },
  },
};
request(options, function (error, response) {
  if (error) throw new Error(error);
  console.log(response.body);
});
