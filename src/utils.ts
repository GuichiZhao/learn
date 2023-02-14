export function fetchAndInstantiate(url: string, importObject: any) {
  return fetch(url)
    .then((response) => response.arrayBuffer())
    .then((bytes) => {
      return WebAssembly.instantiate(bytes, importObject);
    })
    .then((results) => results.instance);
}
